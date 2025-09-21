#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector dp(n + 2, array<int, 2>());
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 2; j++) {
            if (i > 1 && j == 0) {
                if (a[i] == -1 || a[i] == i - 1)
                    dp[i + 1][0] = (dp[i + 1][0] + dp[i][j]) % mod;
                continue;
            }
            int tot = a[i] == -1 ? n : 1;
            if (i < n && (a[i] == -1 || a[i] == i + 1)) {
                dp[i + 1][1] = (dp[i + 1][1] + dp[i][j]) % mod;
                tot--;
            }
            dp[i + 1][0] = (dp[i + 1][0] + static_cast<ll>(dp[i][j]) * tot) % mod;
        }
    }
    cout << dp[n + 1][0] << "\n";
    return 0;
}