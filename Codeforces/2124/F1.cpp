#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int mod = 998244353;
constexpr int Maxn = 105;

int T;
int n, m;
int dp[Maxn][Maxn][Maxn];
int all[Maxn];
bool ok[Maxn][Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            all[i] = 0;
            for (int j = 0; j <= n; j++) {
                fill_n(dp[i][j], n + 1, 0);
                ok[i][j] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            int ind, x; scanf("%d %d", &ind, &x);
            ind--; x--;
            ok[ind][x] = false;
        }
        all[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                for (int l = 0; l < n; l++) if (dp[i][j][l]) {
                    printf("dp[%d][%d][%d] = %d\n", i, j, l, dp[i][j][l]);
                    int nxt = l + 1;
                    if (ok[i][nxt])
                    int nxt = (l + 1) % n;
                    if (ok[i][nxt])
                        if ((nxt + 1) % n == j)
                            all[i + 1] = (all[i + 1] + dp[i][j][l]) % mod;
                        else dp[i + 1][j][nxt] = (dp[i + 1][j][nxt] + dp[i][j][l]) % mod;
                }
            printf("all[%d] = %d\n", i, all[i]);
            for (int j = 0; j < n; j++)
                if (ok[i][j])
                    if ((j + 1) % n == j)
                        all[i + 1] = (all[i + 1] + all[i]) % mod;
                    else dp[i + 1][j][j] = (dp[i + 1][j][j] + all[i]) % mod;
        }
        printf("%d\n", all[n]);
    }
    return 0;
}
