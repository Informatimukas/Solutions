#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector dp(m, false);
    for (int i = 0; i < n; i++) {
        if (dp[0]) {
            cout << "YES\n";
            return 0;
        }
        vector ndp(m, false);
        int a;
        cin >> a;
        ndp[a % m] = true;
        for (int j = 0; j < m; j++)
            if (dp[j])
                ndp[j] = ndp[(j + a) % m] = true;
        dp = ndp;
        if (dp[0]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
