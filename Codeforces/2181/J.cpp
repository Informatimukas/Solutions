#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ld> p(n);
    for (int i = 0; i < n; i++) {
        int pint;
        cin >> pint;
        p[i] = pint / 100.0;
    }
    vector pw2(k + 1, vector<ld>(n));
    vector pwp(k + 1, vector<ld>(n));
    vector pwnp(k + 1, vector<ld>(n));
    for (int j = 0; j < n; j++)
        pw2[0][j] = pwp[0][j] = pwnp[0][j] = 1.0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++) {
            pw2[i][j] = pw2[i - 1][j] * 2 * p[j];
            pwp[i][j] = pwp[i - 1][j] * p[j];
            pwnp[i][j] = pwnp[i - 1][j] * (1 - p[j]);
        }
    vector dp(k + 1, vector<ld>(k + 1, 0.0));
    for (int l = k; l >= 0; l--)
        for (int i = 0, j = l; i <= l; i++, j--) {
            ld tot = 0, decProb = 0, incProb = 0;
            for (int z = 0; z < n; z++) {
                ld prob = pwp[i][z] * pwnp[j][z];
                tot += prob;
                decProb += prob * pwnp[1][z];
                incProb += prob * pwp[1][z];
                dp[i][j] += prob * (pw2[k - l][z] - 1);
            }
            dp[i][j] /= tot;
            dp[i][j] = max(dp[i][j], 0.0l);
            if (l < k) {
                ld sumProb = decProb + incProb;
                decProb /= sumProb;
                incProb /= sumProb;
                dp[i][j] = max(dp[i][j], incProb * dp[i + 1][j] + decProb * dp[i][j + 1]);
            }
        }
    cout << fixed << setprecision(10) << dp[0][0] * 1000 << "\n";
    return 0;
}
