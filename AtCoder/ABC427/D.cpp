#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        vector neigh(n, vector<int>());
        vector dp(2 * k + 1, vector<bool>(n));
        for (int j = 0; j < n; j++)
            dp[0][j] = s[j] == 'A';
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            neigh[a].push_back(b);
        }
        for (int i = 1; i <= 2 * k; i++)
            for (int j = 0; j < n; j++) {
                dp[i][j] = false;
                for (auto& u : neigh[j])
                    if (!dp[i - 1][u]) {
                        dp[i][j] = true;
                        break;
                    }
            }
        cout << (dp[2 * k][0] ? "Alice" : "Bob") << '\n';
    }
    return 0;
}
