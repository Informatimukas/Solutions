#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector dp(m + 1, vector(2, -Inf));
    dp[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= m; j++) {
            dp[j][0] = max(dp[j][0], dp[j][1]);
            dp[j][1] = -Inf;
        }
        for (int j = i; j < n; j += k) {
            vector ndp(m + 1, vector(2, -Inf));
            for (int z = 0; z <= m; z++)
                for (int l = 0; l < 2; l++) {
                    int add = j == 0 ? 1 : ((s[j - 1] != s[j]) ^ l);
                    ndp[z][0] = max(ndp[z][0], dp[z][l] + add);
                    if (z < m && j + k <= n) {
                        add = j == 0 ? 1 : ((s[j - 1] != s[j]) ^ (l ^ 1));
                        ndp[z + 1][1] = max(ndp[z + 1][1], dp[z][l] + add);
                    }
                }
            dp = std::move(ndp);
        }
    }
    int res = -Inf;
    for (int z = 0; z <= m; z++)
        for (int l = 0; l < 2; l++)
            res = max(res, dp[z][l]);
    cout << res << "\n";
    return 0;
}
