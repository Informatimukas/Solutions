#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> seq;
        for (int i = n - 1; i >= 0; i--) {
            while (!seq.empty() && a[seq.back()] <= a[i])
                seq.pop_back();
            seq.push_back(i);
        }
        int cur = 0;
        vector<int> first(k + 1);
        for (auto x : seq | views::reverse)
            while (cur <= a[x])
                first[cur++] = x;
        int mx = cur - 1;
        vector dp(mx + 1, vector(k + 1, -Inf));
        dp[0][k] = 0;
        int res = 0;
        for (int i = 0; i <= mx; i++)
            for (int j = 0; j <= k; j++) if (dp[i][j] >= 0) {
                res = max(res, dp[i][j]);
                for (int ni = i + 1; ni <= mx && ni <= j; ni++)
                    dp[ni][j - ni] = max(dp[ni][j - ni], dp[i][j] + (n - first[ni]) * (ni - i));
            }
        cout << res << "\n";
    }
    return 0;
}
