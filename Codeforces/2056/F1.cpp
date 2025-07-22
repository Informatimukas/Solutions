#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 505;
constexpr int Maxk = 202;

int C[Maxn][Maxn];
int dp[Maxk][Maxk];
int T;
int k, m;
char str[Maxk];

int main() {
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 2;
    }
    dp[0][0] = 1;
    for (int i = 0; i < Maxk; i++)
        for (int j = 0; j < Maxk; j++) if (dp[i][j] && j + 1 < Maxk)
            for (int k = 1; i + k < Maxk; k++)
                dp[i + k][j + 1] = (dp[i + k][j + 1] + dp[i][j] * C[i + k - 1][k - 1]) % 2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &k, &m);
        scanf("%s", str);
        int cnt = 0;
        for (int i = 0; i < k; i++)
            cnt += str[i] == '1';
        int res = 0;
        for (int i = 1; i < m; i++)
            for (int j = 1; j <= i + 1 && j <= cnt; j++)
                if (dp[cnt][j] && C[i][j - 1])
                    res ^= i;
        printf("%d\n", res);
    }
    return 0;
}
