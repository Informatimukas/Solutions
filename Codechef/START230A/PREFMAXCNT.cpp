#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
        vector<int> a(n);
        vector my(n + 1, -1);
        int lft = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == -1)
                ++lft;
            else my[a[i]] = lft;
        }
        vector dp(lft + 1, 0);
        dp[lft] = 1;
        for (int i = n; i > 0; i--) {
            vector ndp(lft + 1, 0);
            if (my[i] == -1) {
                int sum = 0;
                for (int j = lft; j >= 0; j--) {
                    ndp[j] = (ndp[j] + sum) % mod;
                    ndp[j] = (ndp[j] + dp[j]) % mod;
                    sum = (sum + dp[j]) % mod;
                }
                --lft;
            } else for (int j = 0; j <= lft; j++)
                ndp[min(j, my[i])] = (ndp[min(j, my[i])] + dp[j]) % mod;
            swap(dp, ndp);
        }
        cout << dp[0] << "\n";
    }
    return 0;
}
