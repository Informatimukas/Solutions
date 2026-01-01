#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        vector dp(2, Inf);
        dp[0] = 0;
        for (int z = 0; z < s.length(); z++) {
            vector ndp(2, Inf);
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) {
                    int ni = (i + j) % 2;
                    int cand = dp[i] + (j != s[z] - '0') + (ni != t[z] - '0');
                    ndp[ni] = min(ndp[ni], cand);
                }
            dp = std::move(ndp);
        }
        cout << min(dp[0], dp[1]) << "\n";
    }
    return 0;
}
