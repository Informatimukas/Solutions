#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

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
        vector cnt(n + 1, 0);
        for (int j = 0; j < 1 << n; j++)
            if (dp[n][j] == 2)
                cnt[__builtin_popcount(j)]++;
        int res = 0;
        for (int i = 1; i <= m; i++) {
            vector pw0(n + 1, 0), pw1(n + 1, 0);
            pw0[0] = pw1[0] = 1;
            for (int j = 1; j <= n; j++) {
                pw0[j] = static_cast<ll>(pw0[j - 1]) * (i - 1) % mod;
                pw1[j] = static_cast<ll>(pw1[j - 1]) * (m - i + 1) % mod;
            }
            for (int j = 0; j <= n; j++)
                res = (res + static_cast<ll>(pw1[j]) * pw0[n - j] % mod * cnt[j]) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
