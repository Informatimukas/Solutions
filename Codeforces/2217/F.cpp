#include <bits/stdc++.h>
using namespace std;

int Count(int mask, int val) {
    constexpr int Maxb = 25;
    vector dp(Maxb, vector(2, vector(3, 0)));
    dp[Maxb - 1][0][0] = 1;
    for (int i = Maxb - 2; i >= 0; i--)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k <= 2; k++)
                for (int s = 0; s <= 1; s++) {
                    int his = (mask & 1 << i) > 0;
                    int my = (val & 1 << i) > 0;
                    int got = (my ^ s) + s + k;
                    if (got % 2 > his)
                        dp[i][j][k] += dp[i + 1][1][got / 2];
                    else if (got % 2 < his)
                        dp[i][j][k] += dp[i + 1][0][got / 2];
                    else dp[i][j][k] += dp[i + 1][j][got / 2];
                }
    return dp[0][1][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x1, x2;
        cin >> x1 >> x2;
        if (x1 > x2) {
            cout << "1 1\n";
            continue;
        }
        int best = 0, cnt = 1000000000;
        for (int i = 0; i < x1; i++) {
            int cand = Count(x2, i);
            int rcand = 0;
            for (int j = 0; j < x2; j++)
                if (j + (i ^ j) < x2)
                    rcand++;
            if (cand < cnt) {
                cnt = cand;
                best = i;
            }
        }
        for (int i = 0; i < x1; i++)
            if (i + (i ^ best) < x1) {
                cout << 1 + i << " " << x1 - (i ^ best) << "\n";
                break;
            }
    }
    return 0;
}
