#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
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
        vector dp(n + 1, Inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
            if (i + 2 <= n) {
                ll nd = abs(a[i] - a[i + 1]);
                if (i + 2 == n)
                    dp[i + 2] = min(dp[i + 2], dp[i] + nd);
                else dp[i + 3] = min(dp[i + 3], dp[i] + nd + a[i + 2]);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}
