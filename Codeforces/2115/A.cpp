#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int G[Maxn][Maxn];
int T;
int n;
int a[Maxn];
int dp[2][Maxn], cur;

int Gcd(int x, int y) { return x? Gcd(y % x, x): y; }

int main()
{
    for (int i = 1; i < Maxn; i++)
        for (int j = 1; j < Maxn; j++)
            if (i == j) G[i][j] = i;
            else if (i > j) G[i][j] = G[i - j][j];
            else G[i][j] = G[i][j - i];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int g = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            g = Gcd(g, a[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            res += a[i] != g;
        if (res < n) {
            printf("%d\n", res);
            continue;
        }
        fill((int*)dp, (int*)dp + 2 * Maxn, Maxn);
        for (int i = 0; i < n; i++, cur = !cur) {
            dp[!cur][a[i]] = 0;
            for (int j = 1; j < Maxn; j++) if (dp[cur][j] < Maxn) {
                dp[!cur][G[j][a[i]]] = min(dp[!cur][G[j][a[i]]], dp[cur][j] + 1);
                dp[!cur][j] = min(dp[!cur][j], dp[cur][j]);
                dp[cur][j] = Maxn;
            }
        }
        res = dp[cur][g] + n - 1;
        printf("%d\n", res);
    }
	return 0;
}
