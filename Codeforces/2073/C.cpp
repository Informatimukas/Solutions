#include <bits/stdc++.h>
using namespace std;

int Traverse(int v, int p, int c, const vector<vector<int>>& neigh, vector<int>& col) {
    col[v] = c;
    int res = 0;
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        if (col[u])
            res += v < u && col[v] != col[u];
        else res += 1 + Traverse(u, v, -c, neigh, col);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> neigh(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    vector col(n + 1, 0);
    int res = 1;
    for (int i = 1; i <= n; i++)
        if (!col[i])
            res += Traverse(i, 0, 1, neigh, col);
    cout << res << "\n";
    return 0;
}
