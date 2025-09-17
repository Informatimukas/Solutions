#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::reverse(a);
        vector dp(n + 1, vector(n + 1, 0));
        dp[n][n] = 1;
        for (int i = 0; i < n; i++) {
            vector ndp(n + 1, vector(n + 1, 0));
            for (int j = 1; j <= n; j++)
                for (int k = j; k <= n; k++)
                    if (dp[j][k]) {
                        ndp[j][k] = (ndp[j][k] + dp[j][k]) % mod;
                        if (a[i] <= j)
                            ndp[a[i]][k] = (ndp[a[i]][k] + dp[j][k]) % mod;
                        else if (a[i] <= k)
                            ndp[j][a[i]] = (ndp[j][a[i]] + dp[j][k]) % mod;
                    }
            dp = std::move(ndp);
        }
        int res = 0;
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                res = (res + dp[j][k]) % mod;
        cout << res << "\n";
    }
    return 0;
}