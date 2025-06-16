#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 505;
constexpr int mod = 998244353;

int ways[Maxn][Maxn][2];
int T;
int n, k;
char str[Maxn];
int dp[Maxn][Maxn];

int getWays(int a, int b, int val) {
    if (a < 0 || a > b) return 0;
    if (a == b) return 1;
    if (ways[a][b][val] != -1) return ways[a][b][val];
    int res = getWays(a - 1, b - 1, 1 - val);
    if (val == 0) res = (res + getWays(a, b - 1, 1)) % mod;
    return ways[a][b][val] = res;
}

int main() {
    fill((int*)ways, (int*)ways + Maxn * Maxn * 2, -1);
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        for (int i = 0; i <= n; i++)
            fill(dp[i], dp[i] + k + 1, 0);
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j <= k; j++) if (dp[i + 1][j])
                for (int z = j; z <= k; z++)
                    dp[i][z] = (dp[i][z] + static_cast<ll>(dp[i + 1][j]) *
                        getWays(j, z, str[i] - '0')) % mod;
        printf("%d\n", dp[0][k]);
    }
    return 0;
}