#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<ii> seq;
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l < r)
                seq.emplace_back(l, r);
        }
        vector bad(n + 1, vector(2, vector(n + 1, Inf)));
        vector dp(n + 1, vector(n + 1, Inf));
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            int mxr = -1;
            for (auto& [l, r] : seq)
                if (l <= i - 1 && r >= i)
                    mxr = max(mxr, r);
            for (int j = 0; j < 2; j++)
                for (int k = 0; k <= i; k++)
                    if (mxr == -1)
                        dp[i][k] = min(dp[i][k], bad[i][j][k]);
                    else {
                        dp[mxr + 1][k] = min(dp[mxr + 1][k], bad[i][j][k] + mxr + 1 - i);
                        if (j == 0)
                            bad[i + 1][j][k + 1] = min(bad[i + 1][j][k + 1], bad[i][j][k]);
                        else bad[i + 1][j][k] = min(bad[i + 1][j][k], bad[i][j][k]);
                    }
            if (i < n) {
                for (int k = 0; k <= i; k++) {
                    bad[i + 1][0][k + 1] = min(bad[i + 1][0][k + 1], dp[i][k]);
                    bad[i + 1][1][k] = min(bad[i + 1][1][k], dp[i][k]);
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][k] + 1);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int small = 0, eq = 0;
            for (auto x : a)
                if (x < i)
                    small++;
                else if (x == i)
                    eq++;
            int res = 0;
            for (int j = small; j <= small + eq; j++)
                if (dp[n][j] <= small + eq - j) {
                    res = 1;
                    break;
                }
            cout << res;
        }
        cout << "\n";
    }
    return 0;
}
