#include <bits/stdc++.h>
using namespace std;

constexpr int Maxb = 31;
constexpr int Inf = 2000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector dp(Maxb, vector(Maxb, vector(Maxb, -Inf)));
        dp[0][0][0] = 0;
        for (int i = 0; i + 1 < Maxb; i++) {
            int has = static_cast<bool>(n & 1 << i);
            for (int j = 0; j < Maxb; j++)
                for (int l = 0; l < Maxb; l++)
                    if (dp[i][j][l] >= 0)
                        for (int a = 0; j + a < Maxb; a++) {
                            int nl = (has + l + a) / 2;
                            dp[i + 1][j + a][nl] = max(dp[i + 1][j + a][nl], dp[i][j][l] + nl);
                        }
        }
        int res = 0;
        for (int j = 0; j < Maxb && j <= k; j++)
            for (int l = 0; l < Maxb; l++)
                res = max(res, dp[Maxb - 1][j][l] + (k - j));
        cout << res << "\n";
    }
    return 0;
}
