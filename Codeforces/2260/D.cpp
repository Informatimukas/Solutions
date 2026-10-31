#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 7;
constexpr int nil = 3;
constexpr int Inf = 1000000000;

int Solve(const string& s) {
    vector dp(Maxd, Inf);
    dp[nil] = 0;
    for (auto ch : s) {
        vector ndp(Maxd, Inf);
        for (int i = 0; i < Maxd; i++)
            for (int j = -4; j <= 4; j++) if (j) {
                int got = i - nil + j;
                if (got >= 0 && ch == '-' || got <= 0 && ch == '+' || got != 0 && ch == '0')
                    continue;
                got += nil;
                if (0 <= got && got < Maxd)
                    ndp[got] = min(ndp[got], max(dp[i], abs(j)));
            }
        dp = ndp;
    }
    auto res = *ranges::min_element(dp);
    return res >= Inf ? -1 : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << Solve(s) << "\n";
    }
    return 0;
}
