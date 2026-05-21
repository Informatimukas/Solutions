#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    vector<int> neigh;
    int cnt{};
};

void Count(int v, int p, vector<node>& nodes) {
    nodes[v].cnt = 1;
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        Count(u, v, nodes);
        nodes[v].cnt += nodes[u].cnt;
    }
}

vector<vector<ll>> Solve(int v, int p, int d, const vector<node>& nodes, ll& res) {
    vector dp(2, vector(nodes[v].cnt + 1, 0ll));
    int cur = 0;
    for (auto u : nodes[v].neigh) {
        if (u == p) continue;
        auto got = Solve(u, v, d, nodes, res);
        for (int i = 1; i >= 0; i--)
            for (int j = cur; j >= 0; j--)
                for (int ni = 0; ni < 2 && i + ni <= 1; ni++)
                    for (int nj = 0; nj < got[ni].size(); nj++)
                        if (i + ni == 1) {
                            if (j + nj + 1 == d)
                                res += dp[i][j] * got[ni][nj];
                        } else {
                            if (j + nj + 1 == d)
                                res += dp[i][j] * got[ni][nj] * (d - 2);
                            dp[i + ni + 1][j + nj] += dp[i][j] * got[ni][nj];
                        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < got[i].size(); j++)
                dp[i][j] += got[i][j];
        if (d - 1 < got[0].size())
            res += (d - 2) * got[0][d - 1];
        if (d - 1 < got[1].size())
            res += got[1][d - 1];
        cur += nodes[u].cnt;
    }
    for (int i = 0; i < 2; i++)
        for (int j = nodes[v].cnt - 1; j >= 0; j--) {
            dp[i][j + 1] = dp[i][j];
            dp[i][j] = 0;
        }
    dp[0][1]++;
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        Count(1, 0, nodes);
        ll res = 0;
        Solve(1, 0, d, nodes, res);
        cout << res << "\n";
    }
    return 0;
}
