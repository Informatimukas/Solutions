#include <bits/stdc++.h>
using namespace std;

void Visit(int v, const vector<vector<int>>& neigh, vector<bool>& visited) {
    if (visited[v])
        return;
    visited[v] = true;
    for (auto u : neigh[v])
        Visit(u, neigh, visited);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> neigh(n + 1);
    vector visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
    }
    Visit(1, neigh, visited);
    int res = 0;
    for (auto u : visited)
        res += visited[u] != false;
    cout << res << "\n";
    return 0;
}
