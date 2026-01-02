#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector dp(k + 1, vector(n, 0.0));
    vector pw(k + 1, vector<double>(n));
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        int pint;
        cin >> pint;
        p[i] = pint / 100.0;
    }
    ranges::fill(pw[0], 1.0);
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            pw[i][j] = pw[i - 1][j] * 2 * p[j];
    for (int i = 0; i < n; i++)
        dp[0][i] = 1.0 / n;
    double res = 0;
    for (int i = 0; i < k; i++)
        for (int j = i; j >= 0; j--) {
            double cand = 0;
            for (int z = 0; z < n; z++)
                cand += dp[j][z] * (pw[k - i][z] - 1);
            if (cand > 0) {
                res += cand;
                ranges::fill(dp[j], 0.0);
            } else for (int z = 0; z < n; z++) {
                dp[j + 1][z] += dp[j][z] * p[z];
                dp[j][z] *= (1 - p[z]);
            }
        }
    cout << fixed << setprecision(10) << res * 1000 << "\n";
    return 0;
}
