#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
        ll has = (c - 1) * n + (r - 1) * (m - c + 1);
        cout << toPower(2, has) << "\n";
    }
    return 0;
}
