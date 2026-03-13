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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector dp(2, vector(2, ii{Inf, Inf}));
        dp[0][0] = dp[1][0] = {0, 1};
        for (auto ch : s) {
            vector ndp(2, vector(2, ii{Inf, Inf}));
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) {
                    ii cand = dp[i][j];
                    // same
                    cand.first += (i + '0' != ch);
                    ndp[i][1 - j] = min(ndp[i][1 - j], cand);
                    // dif
                    if (j != 1) {
                        cand = dp[i][j];
                        cand.first += (1 - i + '0' != ch);
                        cand.second++;
                        ndp[1 - i][1] = min(ndp[1 - i][1], cand);
                    }
                }
            swap(dp, ndp);
        }
        ii res = min(dp[0][0], dp[1][0]);
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}
