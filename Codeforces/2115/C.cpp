#include <bits/stdc++.h>
using namespace std;

using ld = double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, p;
        cin >> n >> m >> p;
        ld probAll = p / 100.0;
        ld probOne = (100 - p) / 100.0;
        multiset<int> S;
        int sum = 0;
        int mnmob = 400;
        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;
            h--;
            mnmob = min(mnmob, h);
            sum += h;
            S.insert(h);
        }
        vector<int> mn(sum + 1);
        vector<bool> good(sum);
        for (int i = 0; i <= sum; i++) {
            mn[i] = *S.begin();
            good[i] = *S.begin() + 1 >= *S.rbegin();
            S.insert(*S.rbegin() - 1);
            S.erase(prev(S.end()));
        }
        int allowed = min(m, sum);
        vector probFinish(m + 1, vector(allowed + 1, static_cast<ld>(0)));
        probFinish[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            probFinish[i][0] = 1;
            for (int j = 1; j <= i && j < probFinish[i].size(); j++)
                probFinish[i][j] = probAll * probFinish[i - 1][j] +
                    probOne * probFinish[i - 1][j - 1];
        }
        vector probNuke(m + 1, vector(mnmob + 1, vector(n, static_cast<ld>(0))));
        probNuke[0][0][0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= i && j < probNuke[i].size(); j++)
                for (int k = 0; k < n; k++) {
                    ld bestAll = probNuke[i - 1][j][k];
                    if (j > 0)
                        bestAll = max(bestAll, probNuke[i - 1][j - 1][k]);
                    probNuke[i][j][k] += probAll * bestAll;
                    ld bestOne = probNuke[i - 1][j][k];
                    if (k > 0 || j > 0) {
                        int nj = j - (k == 0);
                        int nk = (k + n - 1) % n;
                        bestOne = max(bestOne, probNuke[i - 1][nj][nk]);
                    }
                    probNuke[i][j][k] += probOne * bestOne;
                }
        vector dp(m + 1, vector(mnmob + 1, static_cast<ld>(0)));
        for (int i = m; i >= 0; i--)
            for (int j = 0; j <= i && j < dp[i].size(); j++) {
                int tk = min(i - j, sum);
                int cur = mn[tk] - j;
                if (cur < 0)
                    continue;
                if (good[tk]) {
                    dp[i][j] = probNuke[m - i][cur][(sum - tk) % n];
                    continue;
                }
                if (cur == 0) {
                    int needFinish = min(allowed, max(0, sum - j * n - tk));
                    dp[i][j] = probFinish[m - i][needFinish];
                    continue;
                }
                if (i == m)
                    continue;
                dp[i][j] = probAll * dp[i + 1][j + 1] + probOne * dp[i + 1][j];
            }
        cout << fixed << setprecision(9) << dp[0][0] << "\n";
    }
    return 0;
}