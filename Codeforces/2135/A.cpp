#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector seq(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            seq[a[i]].push_back(i);
        }
        vector dp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            auto ind = distance(seq[a[i]].begin(), ranges::lower_bound(seq[a[i]], i));
            if (ind + a[i] <= seq[a[i]].size()) {
                int ni = seq[a[i]][ind + a[i] - 1] + 1;
                dp[ni] = max(dp[ni], dp[i] + a[i]);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}