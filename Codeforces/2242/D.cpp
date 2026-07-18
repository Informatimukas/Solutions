#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        vector A(a.length() + 1, 0);
        vector B(b.length() + 1, 0);
        for (int i = 0; i < a.length(); i++)
            A[i + 1] = (A[i] + a[i] - '0') % 10;
        for (int i = 0; i < b.length(); i++)
            B[i + 1] = (B[i] + b[i] - '0') % 10;
        if (A[a.length()] != B[b.length()]) {
            cout << "-1\n";
            continue;
        }
        vector dp(a.length() + 1, vector(b.length() + 1, 0));
        for (int i = 0; i <= a.length(); i++)
            for (int j = 0; j <= b.length(); j++) {
                if (i < a.length() && j < b.length() && (A[i] + a[i] - '0') % 10 == (B[j] + b[j] - '0') % 10)
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
                if (i < a.length())
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j < b.length())
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
        cout << dp[a.length()][b.length()] << "\n";
    }
    return 0;
}
