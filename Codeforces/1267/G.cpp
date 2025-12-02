// Next steps: understand why the solution below doesn't work. Maybe worth writing
// a bruteforce solution and stress test this one.
// This solution relies on considering all permutations of picked relics
// and fixing the decision for [number_remaining_relics][remaining_relics_shards_sum]
// the solution does "lef" -> buying random relic;
// "rig" is used for buying the cheapest relic (although we know that all of them will be bought);
#include <bits/stdc++.h>
using namespace std;

using ld = long double;

constexpr int Maxm = 10005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector C(n + 1, vector(n + 1, 0.0l));
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    vector lef(n + 1, vector(Maxm, 0.0l));
    vector rig(n + 1, vector(Maxm, 0.0l));
    vector<int> c(n);
    for (auto& num : c)
        cin >> num;
    ranges::sort(c, greater());
    vector dp(n + 1, vector(Maxm, 0.0l));
    dp[0][0] = 1;
    for (int z = 0; z < n; z++)
        for (int i = z; i >= 0; i--)
            for (int j = Maxm - 1; j >= 0; j--)
                if (dp[i][j] > 0) {
                    // smallest
                    int m = i + 1;
                    int tk = n - m;
                    int rem = j + c[z];
                    ld prob = dp[i][j] / C[n][tk];
                    rig[m][rem] += prob * c[z];
                    lef[m][rem] += prob * (n + m) * x / (2.0l * m);
                    dp[i + 1][j + c[z]] += dp[i][j];
                }
    for (int j = 0; j < Maxm; j++) {
        for (int i = n - 1; i >= 0; i--)
            lef[i][j] += lef[i + 1][j];
        for (int i = 1; i <= n; i++)
            rig[i][j] += rig[i - 1][j];
    }
    vector res(Maxm, vector(n + 1, 1e18l));
    res[0][n] = 0;
    for (int j = 0; j + 1 < Maxm; j++)
        for (int i = 0; i <= n; i++)
            for (int k = 1; k <= i; k++)
                res[j + 1][k] = min(res[j + 1][k], res[j][i] + lef[k][j] + rig[k - 1][j]);
    ld ans = 1e18l;
    for (int i = 0; i <= n; i++)
        ans = min(ans, res[Maxm - 1][i]);
    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}
