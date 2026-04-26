#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 29;
constexpr ll mod = 1000000007;

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

ll C(int n, int k, const vector<ll>& fac, const vector<ll>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        vector has(Maxb, 0);
        vector fac(n + 1, 0ll);
        vector ifac(n + 1, 0ll);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = i * fac[i - 1] % mod;
            ifac[i] = Inv(fac[i]);
        }
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < Maxb; j++)
                if (has[j] > i)
                    b[i] = (b[i] - C(has[j], i, fac, ifac) * (1 << j) % mod + mod) % mod;
            for (int j = 0; j < Maxb; j++)
                if (b[i] & 1 << j)
                    has[j] = i;
        }
        for (int i = 1; i <= n; i++) {
            int res = 0;
            for (int j = 0; j < Maxb; j++)
                if (has[j] >= i)
                    res |= 1 << j;
            cout << res << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
