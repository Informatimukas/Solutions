#include <bits/stdc++.h>
using namespace std;

using ll = long long;

array<ll, 2> getXor(ll x, int bk, const vector<array<ll, 2>>& cnt, map<ll, array<ll, 2>>& M) {
    if (x < cnt.size())
        return cnt[x];
    auto it = M.find(x);
    if (it != M.end())
        return it->second;
    // 1..x
    // 1..cnt.size()-1
    array<ll, 2> my = cnt.back();
    // cnt.size()..x
    ll even = x / 2 - (static_cast<ll>(cnt.size()) - 1) / 2;
    ll odd = x - static_cast<ll>(cnt.size()) + 1 - even;
    my[bk] += odd;
    auto got = getXor(x / 2, bk, cnt, M);
    auto tmp = getXor((cnt.size() - 1) / 2, bk, cnt, M);
    got[0] -= tmp[0];
    got[1] -= tmp[1];
    if (bk)
        swap(got[0], got[1]);
    my[0] += got[0];
    my[1] += got[1];
    M.emplace(x, my);
    return my;
}

ll Sum(ll x, int bk, const vector<array<ll, 2>>& cnt, map<ll, array<ll, 2>>& M, vector<ll>& suma) {
    if (x < suma.size())
        return suma[x];
    ll res = suma.back();
    // suma.size() .. x
    // even
    res += getXor(x / 2, bk, cnt, M)[1] - getXor((suma.size() - 1) / 2, bk, cnt, M)[1];
    // odd
    if (x % 2 == 0)
        x--;
    if (suma.size() <= x)
        res += getXor(x / 2, bk, cnt, M)[1] - getXor((suma.size() - 1) / 2, bk, cnt, M)[1];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll l, r;
        cin >> n >> l >> r;
        vector<ll> a(n + 1), xr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            xr[i] = xr[i - 1] ^ a[i];
        }
        if (n % 2 == 0) {
            a.push_back(xr[(n + 1) / 2]);
            xr.push_back(xr[n] ^ a.back());
        }
        vector<array<ll, 2>> cnt(xr.size());
        for (int i = 1; i < xr.size(); i++) {
            cnt[i] = cnt[i - 1];
            cnt[i][xr[i]]++;
        }
        vector<ll> suma(xr.size());
        for (int i = 1; i < xr.size(); i++)
            suma[i] = suma[i - 1] + a[i];
        map<ll, array<ll, 2>> M;
        cout << Sum(r, xr.back(), cnt, M, suma) - Sum(l - 1, xr.back(), cnt, M, suma) << "\n";
    }
    return 0;
}
