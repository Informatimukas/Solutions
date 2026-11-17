#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector dp(2 * n + 5, Inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int t, w;
        cin >> t >> w;
        for (int j = dp.size() - 1; j >= 0; j--) {
            if (j + t < dp.size())
                dp[j + t] = min(dp[j + t], dp[j]);
            dp[j] += w;
        }
    }
    int cur = 0;
    while (dp[cur] > cur)
        ++cur;
    cout << cur << "\n";
    return 0;
}
