#include <bits/stdc++.h>
using namespace std;

using ld = long double;

void Solve(int v, int p, const string& s, const vector<vector<int>>& neigh, vector<array<ld, 2>>& dp) {
    vector<ld> seq;
    ld cur = 0;
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        Solve(u, v, s, neigh, dp);
        cur += dp[u][1];
        seq.push_back(dp[u][0] - dp[u][1]);
    }
    ranges::sort(seq);
    for (int z = 0; z < 2; z++) {
        dp[v][z] = 1e18l;
        ld my = cur;
        for (int i = 0; i <= seq.size(); i++) {
            if (i + z > 0 || s[v - 1] == '1') {
                ld add = s[v - 1] == '1' ? 0.0l : static_cast<ld>(neigh[v].size()) / (i + z);
                dp[v][z] = min(dp[v][z], my + add);
            }
            if (i < seq.size())
                my += seq[i];
        }
    }
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
        vector<vector<int>> neigh(n + 1);
        vector<array<ld, 2>> dp(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        int root = 1;
        while (s[root - 1] != '1')
            root++;
        ld res = 0;
        for (auto u : neigh[root]) {
            Solve(u, root, s, neigh, dp);
            res += dp[u][1];
        }
        cout << fixed << setprecision(10) << res << "\n";
    }
    return 0;
}
