#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int Solve(const string& s) {
    int n = s.length();
    vector dp(n + 1, vector(n + 1, Inf));
    vector<int> tr(n + 1);
    tr[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        tr[i] = tr[i + 1] + (s[i] == 'T');
    for (int j = 0; j <= n; j++)
        for (int l = 0; l <= n; l++) {
            dp[j][l] = n - (j + tr[n]) + 2 * j - n - l;
            cout << "dp[" << n << "][" << j << "][" << l << "] = " << dp[j][l] << endl;
        }
    for (int i = n - 1; i >= 0; i--) {
        vector ndp(i + 1, vector(i + 1, 0));
        for (int j = 0; j <= i; j++)
            for (int l = 0; l <= i; l++) {
                int cur = n - (j + tr[i]) + (2 * j - i) - l;
                if (s[i] == 'F' || s[i] == 'N')
                    ndp[j][l] = max(ndp[j][l], min(cur, dp[j][max(l, 2 * j - (i + 1))]));
                if (s[i] == 'T' || s[i] == 'N')
                    ndp[j][l] = max(ndp[j][l], min(cur, dp[j + 1][max(l, 2 * (j + 1) - (i + 1))]));
                cout << "ndp[" << i << ", " << j << ", " << l << "] = " << ndp[j][l] << endl;
            }
        dp = ndp;
    }
    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << Solve(s) << "\n";
    }
    return 0;
}
