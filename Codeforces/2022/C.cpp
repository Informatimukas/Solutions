#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

bool Win(const array<char, 3>& arr) {
    int res = 0;
    for (auto x : arr)
        res += x == 'A';
    return res >= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector dp(n + 1, vector(3, -Inf));
        array<string, 2> B{};
        cin >> B[0] >> B[1];
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) {
                if (dp[i][j] < 0)
                    continue;
                int a = i, b = i;
                if (j == 1) ++b;
                else if (j == 2) ++a;
                if (a + 3 <= n && b + 3 <= n) {
                    int cand = dp[i][j];
                    cand += Win({B[0][a], B[0][a + 1], B[0][a + 2]});
                    cand += Win({B[1][b], B[1][b + 1], B[1][b + 2]});
                    dp[i + 3][j] = max(dp[i + 3][j], cand);
                }
                if (j == 0) {
                    int cand = dp[i][j] + Win({B[0][a], B[0][a + 1], B[1][b]});
                    dp[i + 1][2] = max(dp[i + 1][2], cand);
                    cand = dp[i][j] + Win({B[0][a], B[1][b], B[1][b + 1]});
                    dp[i + 1][1] = max(dp[i + 1][1], cand);
                } else if (j == 1) {
                    int cand = dp[i][j] + Win({B[0][a], B[0][a + 1], B[1][b]});
                    dp[i + 2][0] = max(dp[i + 2][0], cand);
                } else {
                    int cand = dp[i][j] + Win({B[0][a], B[1][b], B[1][b + 1]});
                    dp[i + 2][0] = max(dp[i + 2][0], cand);
                }
            }
        cout << dp[n][0] << "\n";
    }
    return 0;
}
