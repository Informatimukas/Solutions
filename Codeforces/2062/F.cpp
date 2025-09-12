#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Maxd = 3;
constexpr ll Inf = 4000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ii> ab(n);
        for (auto& [a, b] : ab) {
            cin >> a >> b;
            a -= b;
        }
        ranges::sort(ab);
        vector<array<ll, Maxd>> dp;
        vector res(n + 1, Inf);
        for (int i = 0; i < ab.size(); i++) {
            vector ndp(i + 2, array<ll, Maxd>());
            for (int j = 0; j < ndp.size(); j++)
                ndp[j].fill(Inf);
            // first
            ndp[1][0] = 2 * ab[i].second;
            ndp[1][1] = ab[i].second;
            for (int j = 1; j < dp.size(); j++)
                for (int k = 0; k < Maxd; k++) if (dp[j][k] < Inf) {
                    ndp[j][k] = min(ndp[j][k], dp[j][k]);
                    // last
                    if (k == 1)
                        res[j + 1] = min(res[j + 1], dp[j][k] + ab[i].first + ab[i].second);
                    else if (k == 2)
                        res[j + 1] = min(res[j + 1], dp[j][k] + 2ll * ab[i].first + 2ll * ab[i].second);
                    // mid usual
                    ndp[j + 1][k] = min(ndp[j + 1][k], dp[j][k] + ab[i].first + 2ll * ab[i].second);
                    // mid special
                    if (k == 0)
                        ndp[j + 1][1] = min(ndp[j + 1][1], dp[j][k] + ab[i].first + ab[i].second);
                    else if (k == 1)
                        ndp[j + 1][2] = min(ndp[j + 1][2], dp[j][k] + ab[i].second);
                }
            swap(dp, ndp);
        }
        for (int i = 2; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}
