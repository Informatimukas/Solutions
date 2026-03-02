#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
constexpr int Maxn = 52;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector dp(Maxn, vector(Maxn, vector(Maxn, 0ll)));
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++)
            for (int k = 0; k < Maxn; k++)
                if (i > 0) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k] * i) % mod;
                    if (j > 0 && k > 0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k - 1] * j) % mod;
                } else if (j > 0)
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j - 1][k] * j) % mod;
                else dp[i][j][k] = 1;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int mx = 0;
        for (int i = 0; i <= n; i++) {
            cin >> a[i];
            if (i > 0)
                mx = max(mx, a[i]);
        }
        for (int i = 1; i <= n; i++)
            if (a[i] < mx - 1) {
                int add = mx - 1 - a[i];
                a[0] -= add;
                a[i] += add;
            }
        if (a[0] < 0) {
            cout << "0\n";
            continue;
        }
        int A = 0, B = 0, C = min(a[0], Maxn - 1);
        for (int i = 1; i <= n; i++)
            if (a[i] == mx) A++;
            else B++;
        cout << dp[A][B][C] << "\n";
    }
    return 0;
}
