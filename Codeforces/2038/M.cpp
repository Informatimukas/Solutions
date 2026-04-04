#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

using ii = pair<int, int>;

constexpr int Maxc = 5;
constexpr ld Inf = 1e9l;

array<int, 6> Get(int s, array<ii, 5> seq) {
    seq.back().first -= seq.back().second;
    int lst = s - 1;
    for (int i = lst; i >= 0; i--)
        if (seq[i].second > 0) {
            seq.back().first += seq[i].first - seq[i].second;
            seq[i].first = seq[i].second = 0;
            swap(seq[i], seq[lst--]);
            --s;
        }
    return {s, seq[0].first, seq[1].first, seq[2].first, seq[3].first, seq[4].first};
}

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
            for (int a = 0; a <= Maxc; a++)
                for (int b = 0; b <= (s >= 2 ? Maxc : 0) && a + b <= Maxc; b++)
                    for (int c = 0; c <= (s >= 3 ? Maxc : 0) && a + b + c <= Maxc; c++)
                        for (int d = 0; d <= (s >= 4 ? Maxc : 0) && a + b + c + d <= Maxc; d++)
                            for (int t = 0; a + b + c + d + t <= Maxc; t++) {
                                auto& res = dp[l][s][a][b][c][d][t];
                                if (a + b + c + d + t < Maxc) {
                                    int lfta = Maxc - a;
                                    int lftb = s >= 2 ? Maxc - b : 0;
                                    int lftc = s >= 3 ? Maxc - c : 0;
                                    int lftd = s >= 4 ? Maxc - d : 0;
                                    int lftt = l - lfta - lftb - lftc - lftd;
                                    if (lftt < 0) {
                                        res = Inf;
                                        continue;
                                    }
                                    if (lfta)
                                        res += static_cast<ld>(lfta) / l *
                                            dp[l - 1][s][a + 1][b][c][d][t];
                                    if (lftb)
                                        res += static_cast<ld>(lftb) / l *
                                            dp[l - 1][s][a][b + 1][c][d][t];
                                    if (lftc)
                                        res += static_cast<ld>(lftc) / l *
                                            dp[l - 1][s][a][b][c + 1][d][t];
                                    if (lftd)
                                        res += static_cast<ld>(lftd) / l *
                                            dp[l - 1][s][a][b][c][d + 1][t];
                                    if (lftt)
                                        res += static_cast<ld>(lftt) / l *
                                            dp[l - 1][s][a][b][c][d][t + 1];
                                } else if (a == Maxc || b == Maxc || c == Maxc || d == Maxc)
                                    res = 0;
                                else {
                                    res = Inf;
                                    for (int ta = 0; ta <= a; ta++)
                                        for (int tb = 0; tb <= b; tb++)
                                            for (int tc = 0; tc <= c; tc++)
                                                for (int td = 0; td <= d; td++)
                                                    for (int tt = 0; tt <= t; tt++)
                                                        if (ta + tb + tc + td + tt > 0) {
                                                            auto ret = Get(s,
                                                                array<ii, 5>{ii{a, ta}, {b, tb},
                                                                    {c, tc}, {d, td},
                                                                    {t, tt}});
                                                            res = min(res, 1 + dp[l][ret[0]][ret[1]][ret[2]][ret[3]][ret[4]][ret[5]]);
                                                        }
                                }
                            }
    cout << fixed << setprecision(10) << dp[13 * n][n][0][0][0][0][0] << "\n";
    return 0;
}