#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;
constexpr int Maxn = 5002;
constexpr int Maxm = Maxn * Maxn;

int dp[Maxn][Maxn][2][2];
int pw4[Maxm];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pw4[0] = 1;
    for (int i = 1; i < Maxm; ++i)
        pw4[i] = 4ll * pw4[i - 1] % mod;
    vector down(2, vector(2, vector(2, vector(2, 0))));
    vector right(2, vector(2, vector(2, vector(2, 0))));
    vector same(2, vector(2, 0));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 4; k++)
                if (i == 0 && k != 2) {
                    down[i][j][0][k == 1] = (down[i][j][0][k == 1] + 3) % mod;
                    down[i][j][1][k == 1] = (down[i][j][1][k == 1] + 1) % mod;
                } else if (j == 0 && k != 3) {
                    right[i][j][k == 0][0] = (right[i][j][k == 0][0] + 3) % mod;
                    right[i][j][k == 0][1] = (right[i][j][k == 0][1] + 1) % mod;
                } else same[i][j] = (same[i][j] + 1) % mod;
    for (int i = 1; i < Maxn; i++)
        for (int j = 1; j < Maxn; j++)
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++) {
                    dp[i][j][a][b] = static_cast<ll>(same[a][b]) * pw4[(i + 1) * (j + 1) - 4] % mod;
                    for (int c = 0; c < 2; c++)
                        for (int d = 0; d < 2; d++) {
                            dp[i][j][a][b] = (dp[i][j][a][b] +
                                static_cast<ll>(down[a][b][c][d]) * pw4[j - 1] % mod *
                                dp[i - 1][j][c][d] +
                                static_cast<ll>(right[a][b][c][d]) * pw4[i - 1] % mod *
                                dp[i][j - 1][c][d]) % mod;
                        }
                }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int res = static_cast<ll>(dp[n][m][0][0]) * 4 * 3 * 3 % mod;
        res = (res + static_cast<ll>(dp[n][m][1][0]) * 4 * 3) % mod;
        res = (res + static_cast<ll>(dp[n][m][0][1]) * 4 * 3) % mod;
        res = (res + static_cast<ll>(dp[n][m][1][1]) * 4) % mod;
        cout << res << "\n";
    }
    return 0;
}
