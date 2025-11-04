// Next steps: I used dp on the sequence of the dfs tree. The issue was that I could not
// efficiently exclude the top of the tree for the first picked edge.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

void Traverse(int v, int p, const vector<vector<int>>& neigh, vector<int>& rig) {
    static int cur = -1;
    int my = ++cur;
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        Traverse(u, v, neigh, rig);
    }
    rig[my] = cur + 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector neigh(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    vector<int> rig(n);
    Traverse(1, 0, neigh, rig);
    vector<int> pw2(n);
    pw2[0] = 1;
    for (int i = 1; i < n; i++)
        pw2[i] = 2 * pw2[i - 1] % mod;
    vector dp(n + 1, vector(k + 1, 0));
    for (int i = 1; i < n; i++) {
        // from 0
        int good = (pw2[i] - 1 + mod) % mod;
        // given good
        dp[rig[i]][1] = (dp[rig[i]][1] - good + mod) % mod;
        dp[i + 1][1] = (dp[i + 1][1] + 2ll * good) % mod;
        // given bad
        dp[n][1] = (dp[n][1] + 1) % mod;
        dp[rig[i]][1] = (dp[rig[i]][1] - 1 + mod) % mod;
        dp[i + 1][1] = (dp[i + 1][1] + 2) % mod;
        // from others
        for (int j = 1; j <= k; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + 2ll * dp[i][j]) % mod;
            if (j < k) {
                dp[rig[i]][j + 1] = (dp[rig[i]][j + 1] - dp[i][j] + mod) % mod;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 2ll * dp[i][j]) % mod;
            }
        }
    }
    for (int j = 1; j <= k; j++)
        cout << "j = " << j << ", dp = " << dp[n][j] << endl;
    return 0;
}