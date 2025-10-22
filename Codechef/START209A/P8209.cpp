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

int getMult(const vector<int>& fac, const vector<int>& ifac, int m, int dif) {
    if (dif > m)
        return 0;
    return static_cast<ll>(fac[m]) * ifac[m - dif] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> fac(m + 1), ifac(m + 1);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= m; i++) {
            fac[i] = static_cast<ll>(i) * fac[i - 1] % mod;
            ifac[i] = Inv(fac[i]);
        }
        vector dp(n + 1, vector(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= m; j++) {
                dp[i + 1][j] = (dp[i + 1][j] + static_cast<ll>(dp[i][j]) * j) % mod;
                if (j < m)
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
            }
        int res = 0;
        for (int i = 1; i < n; i++) {
            int add = 0;
            for (int j = 1; j <= m; j++) {
                int a0 = static_cast<ll>(dp[i - 1][j - 1]) *
                    getMult(fac, ifac, m - 1, j - 1) % mod;
                int a1 = static_cast<ll>(dp[i - 1][j]) * j % mod *
                    getMult(fac, ifac, m - 1, j - 1) % mod;
                int b0 = static_cast<ll>(dp[n - i][j]) *
                    getMult(fac, ifac, m - 1, j) % mod;
                int b1 = static_cast<ll>(dp[n - i][j]) * j % mod *
                    getMult(fac, ifac, m - 1, j - 1) % mod;
                add = (add + static_cast<ll>(a0) * b0) % mod;
                add = (add + static_cast<ll>(a0) * b1) % mod;
                add = (add + static_cast<ll>(a1) * b0) % mod;
            }
            res = (res + static_cast<ll>(m) * add) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
