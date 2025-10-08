#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return static_cast<ll>(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
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
        int need = 2 * n + 5;
        vector<int> fac(need), ifac(need);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < fac.size(); i++) {
            fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
            ifac[i] = Inv(fac[i]);
        }
        for (int i = 1; i <= n; i++) {
            int res = C(2 * n, n, fac, ifac);
            res = (res - C(2 * n - i - 1, n, fac, ifac) + mod) % mod;
            res = (res - C(n + i - 1, n, fac, ifac) + mod) % mod;
            cout << res << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
