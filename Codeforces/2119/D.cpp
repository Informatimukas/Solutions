#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, mod;
        cin >> n >> mod;
        vector dp(n + 1, vector(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
                dp[i + 1][j] = (dp[i + 1][j] +
                    static_cast<ll>(dp[i][j]) * (j + 1) % mod * (n - i)) % mod;
            }
        int res = 0;
        for (int j = 0; j <= n; j++)
            res = (res + dp[n][j]) % mod;
        cout << res << "\n";
    }
    return 0;
}
