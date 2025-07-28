#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int mod = 998244353;
constexpr int Maxn = 105;

int T;
int n, m;
int dp[Maxn][Maxn][Maxn];
int nt[Maxn][Maxn];
bool ok[Maxn][Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                fill_n(dp[i][j], n + 1, 0);
                nt[i][j] = 0;
                ok[i][j] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            int ind, x; scanf("%d %d", &ind, &x);
            ind--; x--;
            ok[ind][x] = false;
        }
        nt[0][n] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                for (int l = 0; l < n; l++) if (dp[i][j][l]) {
                    if (j == 0) {
                        if (ok[i][l + 1])
                            dp[i + 1][j][l + 1] = (dp[i + 1][j][l + 1] + dp[i][j][l]) % mod;
                        nt[i][l + 1] = (nt[i][l + 1] + dp[i][j][l]) % mod;
                    } else if (j <= l) {
                        if (l + 1 <= n && ok[i][l + 1])
                            dp[i + 1][j][l + 1] = (dp[i + 1][j][l + 1] + dp[i][j][l]) % mod;
                        if (ok[i][0])
                            dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][l]) % mod;
                    } else if (l + 1 == j)
                        nt[i][n] = (nt[i][n] + dp[i][j][l]) % mod;
                    else if (ok[i][l + 1])
                        dp[i + 1][j][l + 1] = (dp[i + 1][j][l + 1] + dp[i][j][l]) % mod;
                }
            int all = 0;
            for (int j = 0; j <= n; j++)
                all = (all + nt[i][j]) % mod;
            for (int j = 0; j < n; j++) {
                int ways = (all - nt[i][j] + mod) % mod;
                if (ok[i][j])
                    dp[i + 1][j][j] = (dp[i + 1][j][j] + ways) % mod;
            }
        }
        int res = 0;
        for (int j = 0; j <= n; j++)
            for (int l = 0; l < n; l++)
                if (j == 0 || l + 1 == j)
                res = (res + dp[n][j][l]) % mod;
        printf("%d\n", res);
    }
    return 0;
}
