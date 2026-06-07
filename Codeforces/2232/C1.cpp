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
        int n, x, s;
        cin >> n >> x >> s;
        vector dp(x + 1, -Inf);
        dp[x] = 0;
        string seq;
        cin >> seq;
        for (int i = 0; i < n; i++) {
            vector ndp(x + 1, -Inf);
            for (int j = 0; j <= x; j++) {
                if (j > 0 && seq[i] != 'E')
                    ndp[j - 1] = max(ndp[j - 1], dp[j] + 1);
                int lft = (x - j) * s - dp[j];
                if (lft > 0 && seq[i] != 'I')
                    ndp[j] = max(ndp[j], dp[j] + 1);
                ndp[j] = max(ndp[j], dp[j]);
            }
            dp = ndp;
        }
        cout << *ranges::max_element(dp) << "\n";
    }
    return 0;
}
