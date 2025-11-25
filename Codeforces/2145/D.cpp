#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 31;
constexpr int Maxm = Maxn * (Maxn - 1) / 2 + 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector dp(Maxn, vector(Maxm, vector(Maxn, 0)));
    for (int k = 0; k < Maxn; k++)
        dp[0][0][k] = 1;
    for (int i = 1; i < Maxn; i++)
        for (int j = 0; j < Maxm; j++)
            for (int k = 0; k < Maxn; k++)
                if (k + 1 && dp[i - 1][j][k + 1])
                    dp[i][j][k] = 1;
                else if (j - k * i >= 0 && dp[i - 1][j - k * i][1])
                    dp[i][j][k] = -1;
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (!dp[n - 1][k][1]) {
            cout << "0\n";
            continue;
        }
        vector<int> seq(n);
        int pnt = 0;
        seq[pnt++] = 1;
        int i = n - 1, j = k, z = 1;
        while (i > 0) {
            seq[pnt++] = dp[i][j][z];
            if (dp[i][j][z] == 1)
                z++;
            else {
                j -= i * z;
                z = 1;
            }
            i--;
        }
        vector<int> res(n);
        pnt = 1;
        for (int c = n - 1; c >= 0; c--)
            if (seq[c] == -1)
                res[c] = pnt++;
        for (int c = 0; c < n; c++)
            if (seq[c] == 1)
                res[c] = pnt++;
        for (int c = 0; c < n; c++)
            cout << res[c] << (c + 1 < n ? ' ' : '\n');
    }
    return 0;
}