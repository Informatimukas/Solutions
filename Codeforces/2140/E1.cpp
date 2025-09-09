#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int k;
        cin >> k;
        int goodMask = 0;
        while (k--) {
            int x;
            cin >> x;
            goodMask |= 1 << (x - 1);
        }
        if (m == 1) {
            cout << "1\n";
            continue;
        }
        vector dp(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) {
            dp[i].resize(1 << i);
            if (i == 1) {
                dp[i][0] = 1;
                dp[i][1] = 2;
                continue;
            }
            bool needMax = n % 2 == i % 2;
            for (int j = 0; j < 1 << i; j++) {
                dp[i][j] = needMax ? 1 : 2;
                for (int l = 0; l < i; l++)
                    if (goodMask & 1 << l) {
                        int newMask = ((j >> (l + 1)) << l) | (j & ((1 << l) - 1));
                        if (needMax && dp[i - 1][newMask] == 2) {
                            dp[i][j] = 2;
                            break;
                        }
                        if (!needMax && dp[i - 1][newMask] == 1) {
                            dp[i][j] = 1;
                            break;
                        }
                    }
            }
        }
        int res = 0;
        for (int j = 0; j < 1 << n; j++)
            res += dp[n][j];
        cout << res << "\n";
    }
    return 0;
}
