#include <bits/stdc++.h>
using namespace std;

using ll = long long;

array<ll, 3> Traverse(ll x, ll y, vector<ll>& b) {
    ll absorb = 0;
    for (auto& num : b) {
        auto tka = min(x, num / 2);
        auto tkb = num - tka;
        x -= tka;
        y -= tkb;
        absorb += tkb - tka;
    }
    return {x, y, absorb};
}

bool Solve(ll x, ll y, vector<ll> a, vector<ll> b) {
    if (x < 0 || y < 0)
        return false;
    if (a.empty()) {
        auto got = Traverse(x, y, b);
        return got[1] >= 0 && got[1] + got[2] >= got[0];
    }
    if (b.empty()) {
        auto got = Traverse(y, x, a);
        return got[1] >= 0 && got[1] + got[2] >= got[0];
    }
    bool okx = accumulate(a.begin(), a.end(), 0ll) <= x;
    bool oky = accumulate(b.begin(), b.end(), 0ll) <= y;
    if (okx && oky)
        return true;
    if (!okx && !oky)
        return false;
    if (oky) {
        swap(x, y);
        swap(a, b);
    }
    x -= accumulate(a.begin(), a.end(), 0);
    auto got = Traverse(x, y, b);
    return got[0] >= 0 && got[1] >= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        vector<ll> a, b;
        for (int i = 0; i < n; i++) {
            ll p;
            cin >> p;
            --p;
            if (s[i] == '0') {
                --x;
                a.push_back(p);
            } else {
                --y;
                b.push_back(p);
            }
        }
        cout << (Solve(x, y, a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
