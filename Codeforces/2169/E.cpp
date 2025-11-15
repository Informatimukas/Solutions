#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxd = 4;
constexpr ll Inf = 9000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (auto& z : x)
            cin >> z;
        for (auto& z : y)
            cin >> z;
        vector<int> c(n);
        for (auto& z : c)
            cin >> z;
        vector dp(n + 1, vector(1 << Maxd, -Inf));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1 << Maxd; j++)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + c[i]);
            for (int k = 1; k < 1 << Maxd; k++) {
                ll add = 0;
                if (k & 1) add -= 2 * x[i];
                if (k & 2) add += 2 * x[i];
                if (k & 4) add -= 2 * y[i];
                if (k & 8) add += 2 * y[i];
                for (int j = 0; j < 1 << Maxd; j++)
                    if (!(j & k)) {
                        int nj = j | k;
                        dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + add);
                    }
            }
        }
        cout << dp[n][(1 << Maxd) - 1] << "\n";
    }
    return 0;
}
