#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    vector dp(n + 2, vector(n + 2, -Inf));
    dp[1][1] = 0;
    for (int i = 1; i <= n; i++) {
        int pnt = i, cur = -Inf;
        for (int j = i; j <= n; j++) {
            while (pnt > 0 && sum[i - 1] - sum[pnt - 1] <= sum[j] - sum[i - 1])
                cur = max(cur, dp[i][pnt--]);
            dp[j + 1][i] = max(dp[j + 1][i], cur + 1);
        }
    }
    auto res = *ranges::max_element(dp[n + 1]);
    cout << n - res << "\n";
    return 0;
}
