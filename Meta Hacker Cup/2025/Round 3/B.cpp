#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        vector<ll> sum(n);
        for (int i = 0; i < n; i++) {
            sum[i] = a[i];
            if (i)
                sum[i] += sum[i - 1];
        }
        vector mx(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur = max(cur, b[j]);
                mx[i][j] = cur;
            }
        }
        vector dp(n + 1, vector(n + 1, vector(2, Inf)));
        dp[0][0][1] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                for (int k = 0; k < 2; k++)
                    if (dp[i][j][k] < Inf) {
                        if (j >= b[i])
                            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k]);
                        if (k == 1) {
                            if (j + 1 >= b[i])
                                dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1],
                                    dp[i][j][k] + a[i]);
                        } else if (i + j + 1 <= n && (j == 0 || j >= mx[i][i + j - 1]) &&
                            j + 1 >= b[i + j]) {
                            ll add = sum[i + j];
                            if (i - 1 >= 0)
                                add -= sum[i - 1];
                            dp[i + j + 1][j + 1][1] = min(dp[i + j + 1][j + 1][1],
                                dp[i][j][k] + add);
                        }
                    }
        ll res = Inf;
        for (int j = 0; j <= n; j++)
            for (int k = 0; k < 2; k++)
                res = min(res, dp[n][j][k]);
        cout << res << "\n";
    }
    return 0;
}
