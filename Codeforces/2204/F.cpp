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

ll Inv(ll x) { return toPower(x, mod - 2); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        ll res = 0;
        for (int l = 0; l < n; l++)
            for (int r = l; r < n; r++) {
                vector seq(a.begin() + l, a.begin() + r + 1);
                ranges::sort(seq);
                if (k <= seq[0] - 1)
                    res = (res + (1 + k) * Inv(seq[0])) % mod;
                else if (k <= 2 * (seq[0] - 1))
                    res = (res + seq[0] * Inv(2 * seq[0] - k - 1)) % mod;
                else res = (res + seq[0] + (k - 2 * (seq[0] - 1))) % mod;
                res = accumulate(seq.begin() + 1, seq.end(), res,
                    [](ll res, ll num) {
                    return (res + Inv(num)) % mod;
                });
            }
        cout << res << "\n";
    }
    return 0;
}
