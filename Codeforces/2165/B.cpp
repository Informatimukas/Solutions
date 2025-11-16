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
        map<int, int> M;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            M[a]++;
        }
        vector<int> seq;
        for (auto& x : M | views::values)
            seq.push_back(x);
        ranges::sort(seq);
        vector dp(seq.size() + 1, vector(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < seq.size(); i++)
            for (int j = 0; j <= n; j++) {
                if (i + 1 < seq.size() || j >= seq[i])
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                int nj = min(j + seq[i], n);
                dp[i + 1][nj] = (dp[i + 1][nj] + static_cast<ll>(dp[i][j]) * seq[i]) % mod;
            }
        int res = 0;
        for (int j = 0; j <= n; j++)
            res = (res + dp[seq.size()][j]) % mod;
        cout << res << "\n";
    }
    return 0;
}
