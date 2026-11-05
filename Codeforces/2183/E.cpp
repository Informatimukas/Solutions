#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> divs(m + 1);
        for (int i = 1; i <= m; i++)
            for (int j = i; j <= m; j += i)
                divs[j].push_back(i);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector dp(m + 1, 0);
        dp[1] = 1;
        for (int i = 0; i < n; i++) {
            vector ndp(m + 1, 0);
            for (int j = 1; j <= m; j++) {
                if (a[i] && a[i] != j) {
                    dp[j] = 0;
                    continue;
                }
                for (auto d : divs[j]) {
                    if (j + d > m)
                        continue;
                    ndp[j + d] = (ndp[j + d] + dp[j]) % mod;
                }
            }
            if (i == n - 1)
                break;
            dp = ndp;
        }
        int res = 0;
        for (auto x : dp)
            res = (res + x) % mod;
        cout << res << "\n";
    }
    return 0;
}
