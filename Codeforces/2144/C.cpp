#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        vector dp(n, array<int, 2>());
        dp[0][0] = dp[0][1] = 1;
        for (int i = 0; i + 1 < n; i++)
            for (int j = 0; j < 2; j++) if (dp[i][j]) {
                ii my = {a[i], b[i]};
                if (j) swap(my.first, my.second);
                for (int k = 0; k < 2; k++) {
                    ii oth = {a[i + 1], b[i + 1]};
                    if (k) swap(oth.first, oth.second);
                    if (my.first <= oth.first && my.second <= oth.second)
                        dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
                }
            }
        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << "\n";
    }
    return 0;
}
