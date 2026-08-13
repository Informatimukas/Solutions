#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 61;
constexpr ll Inf = 4000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector dp(Maxn, vector(Maxn, vector(Maxn, Inf)));
    dp[0][0][0] = 0;
    for (int i = 1; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++)
            for (int k = 0; k < Maxn; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= i)
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - i][k] + (1ll << i));
                if (k >= i)
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - i] + (1ll << i));
            }
    int T;
    cin >> T;
    while (T--) {
        ll x, y;
        cin >> x >> y;
        ll res = Inf;
        for (int j = 0; j < Maxn; j++)
            for (int k = 0; k < Maxn; k++)
                if (x / (1ll << j) == y / (1ll << k))
                    res = min(res, dp[Maxn - 1][j][k]);
        cout << res << "\n";
    }
    return 0;
}
