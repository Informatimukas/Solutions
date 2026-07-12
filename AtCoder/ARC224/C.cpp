#include <bits/stdc++.h>
using namespace std;

void Solve(const vector<vector<int>>& neigh, vector<int>& res, int v, int col) {
    if (res[v] != -1)
        return;
    res[v] = col;
    for (auto u : neigh[v])
        Solve(neigh, res, u, col + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> neigh(n + 1);
        vector res(n + 1, -1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Solve(neigh, res, 1, 0);
        for (int i = 1; i <= n; i++)
            cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
