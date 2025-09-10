#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector all(n + 1, 0);
        vector dp(n + 1, vector(n + 1, 0));
        vector incr(n, vector(n, 1));
        vector solve(n + 1, vector(n, 0));
        while (m--) {
            int ind, x;
            cin >> ind >> x;
            incr[ind - 1][x - 1] = 0;
        }
        all[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++)
                if (incr[i][j] == 1 && i + 1 < n && j + 1 < n)
                    incr[i][j] += incr[i + 1][j + 1];
            for (int j = 1; j < n; j++) {
                int my = incr[i][0] >= j ? all[i + j] : 0;
                solve[i][j] = (my + solve[i + 1][j]) % mod;
            }
            for (int j = 1; j <= incr[i][0]; j++) {
                int ways = (all[i + j] - dp[i + j][j] + mod) % mod;
                all[i] = (all[i] + ways) % mod;
            }
            for (int j = 1; j < n; j++) {
                int ways = solve[i + 1][j];
                if (int sub = i + incr[i][j] + 1; sub <= n)
                    ways = (ways - solve[sub][j] + mod) % mod;
                all[i] = (all[i] + ways) % mod;
                dp[i][j] = (dp[i][j] + ways) % mod;
            }
        }
        cout << all[0] << "\n";
    }
    return 0;
}
