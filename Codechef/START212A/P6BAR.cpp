#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        k--;
        vector dp(n + 1, vector(n + 1, 0));
        dp[1][n > 1] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 0; j <= i; j++) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 2ll * dp[i][j]) % mod;
                dp[i + 1][j] = (dp[i + 1][j] + static_cast<ll>(i - 1) * dp[i][j]) % mod;
            }
        cout << dp[n][k] << "\n";
    }
    return 0;
}