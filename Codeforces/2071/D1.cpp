#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getXor(ll x, const vector<ll>& xr) {
    if (x < xr.size())
        return xr[x];
    ll res = xr.back();
    if (x % 2 == 0)
        res ^= getXor(x / 2, xr);
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
        if (l < a.size()) {
            cout << a[l] << "\n";
            continue;
        }
        cout << getXor(l / 2, xr) << "\n";
    }
    return 0;
}
