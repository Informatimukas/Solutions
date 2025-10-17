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
        ranges::sort(seq);
        vector<ii> spec;
        for (auto& p : seq)
            if (spec.empty() || spec.back().second <= p.first)
                spec.push_back(p);
            else spec.back().second = max(spec.back().second, p.second);
        vector mark(n + 1, false);
        vector beg(n + 1, false);
        vector x(n + 1, false);
        for (int i = 0; i < spec.size(); i++) {
            if (i && spec[i - 1].second == spec[i].first)
                x[spec[i].first] = true;
            else beg[spec[i].first] = true;
            for (int j = spec[i].first; j <= spec[i].second; j++)
                mark[j] = true;
        }
        vector dp(n + 1, vector(n + 1, vector(2, Inf)));
        dp[0][0][0] = dp[0][0][1] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                for (int k = 0; k < 2; k++)
                    if (dp[i][j][k] < Inf) {
                        if (x[i]) {
                            dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + 1);
                            dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][k] + 1);
                        }
                        int nj = k == 0 ? j + 1 : j;
                        dp[i + 1][nj][k] = min(dp[i + 1][nj][k], dp[i][j][k]);
                        if (i + 1 == n || !mark[i + 1] || beg[i + 1])
                            dp[i + 1][nj][1 - k] = min(dp[i + 1][nj][1 - k], dp[i][j][k]);
                    }
        for (int i = 1; i <= n; i++) {
            int small = 0, eq = 0, big = 0;
            for (auto& el : a)
                if (el < i) small++;
                else if (el == i) eq++;
                else big++;
            int found = 0;
            for (int j = 0; j <= n; j++) {
                int nsmall = j;
                int neq = min(dp[n][j][0], dp[n][j][1]);
                if (neq >= Inf)
                    continue;
                int nbig = n - nsmall - neq;
                int tot = max(0, nsmall - small) + max(0, nbig - big) + neq;
                if (tot <= eq) {
                    found = 1;
                    break;
                }
            }
            cout << found;
        }
        cout << "\n";
    }
    return 0;
}
