#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr ll Inf = 1000000000000000000ll;

int T;
int n, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector<ll> A(n + 1);
        A[0] = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            A[i] = A[i - 1] + a;
        }
        vector<ll> B(m);
        for (int i = 0; i < m; i++)
            scanf("%d", &B[i]);
        vector dp(n + 1, vector(m, Inf));
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < m; j++) {
                if (i < n) {
                    int to = ranges::upper_bound(A, A[i] + B[j]) - A.begin() - 1;
                    dp[to][j] = min(dp[to][j], dp[i][j] + m - 1 - j);
                }
                if (j + 1 < m)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
            }
        printf("%lld\n", dp[n][m - 1] >= Inf? -1: dp[n][m - 1]);
    }
    return 0;
}