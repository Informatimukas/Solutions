#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<array<array<int, 2>, 2>> dp(n + 1);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            if (s[i] == '?' || s[i] == j + '0')
                for (int k = 0; k < 10; k++)
                    if (t[i] == '?' || t[i] == k + '0')
                        for (int a = 0; a < 2; a++)
                            for (int b = 0; b < 2; b++) {
                                int na = a, nb = b;
                                if (j < k)
                                    na = 1;
                                if (j > k)
                                    nb = 1;
                                dp[i + 1][na][nb] = (dp[i + 1][na][nb] + dp[i][a][b]) % mod;
                            }
    cout << dp[n][1][1] << "\n";
    return 0;
}
