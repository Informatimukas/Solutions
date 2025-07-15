#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 300005;
constexpr int Inf = 1000000000;

int T;
int n;
int a[Maxn];
int dp[Maxn][3];

int Delta(int x, int a) {
    if (x < a) return 1;
    if (x == a) return 0;
    return -1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill((int*)dp, (int*)dp + (n + 1) * 3, -Inf);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + Delta(dp[i][0], a));
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][0]);
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][1]);
            dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + Delta(dp[i][1], a));
            dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + Delta(dp[i][2], a));
        }
        printf("%d\n", max(dp[n][1], dp[n][2]));
    }
    return 0;
}