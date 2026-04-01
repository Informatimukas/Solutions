#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

constexpr int Maxc = 5;
constexpr ld Inf = 1e9l;

int main() {
    int n;
    cin >> n;
    vector dp(13 * n + 1, vector(n + 1, vector(Maxc + 1,
        vector(Maxc + 1, vector(Maxc + 1,
        vector(Maxc + 1, vector<ld>(Maxc + 1)))))));
    for (int i = 0; i <= 13 * n; i++)
        for (int j = 0; j <= Maxc; j++)
            dp[i][0][0][0][0][0][j] = Inf;
    for (int l = 0; l <= 13 * n; l++)
        for (int s = 1; s <= n; s++)
            for (int a = Maxc; a >= 0; a--)
                for (int b = s >= 2 ? Maxc : 0; b >= 0; b--) if (a + b <= Maxc)
                    for (int c = s >= 3 ? Maxc : 0; c >= 0; c--) if (a + b + c <= Maxc)
                        for (int d = s >= 4 ? Maxc : 0; d >= 0; d--) if (a + b + c + d <= Maxc)
                            for (int t = Maxc; t >= 0; t--) if (a + b + c + d + t <= Maxc)
                                if (a + b + c + d + t < Maxc) {
                                    int lfta = Maxc - a;
                                    int lftb = s >= 2 ? Maxc - b : 0;
                                    int lftc = s >= 3 ? Maxc - c : 0;
                                    int lftd = s >= 4 ? Maxc - d : 0;
                                    int lftt = l - lfta - lftb - lftc - lftd;
                                    if (lftt < 0) {
                                        dp[l][s][a][b][c][d][t] = Inf;
                                        continue;
                                    }
                                    if (lfta)
                                        dp[l][s][a][b][c][d][t]
                                }
    return 0;
}