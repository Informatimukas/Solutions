#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

void Print(int v, const vector<int>& par) {
    vector<int> res;
    while (v) {
        res.push_back(v);
        v = par[v];
    }
    cout << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << (i - 1 >= 0 ? ' ' : '\n');
}

void Solve(int n, const vector<vector<int>>& neigh, int s) {
    vector dist(n + 1, Inf);
    vector col(n + 1, 0);
    vector par(n + 1, 0);
    queue<int> Q;
    for (auto u : neigh[s]) {
        dist[u] = 1;
        col[u] = u;
        par[u] = s;
        Q.push(u);
    }
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto u : neigh[v])
            if (dist[u] == Inf) {
                dist[u] = dist[v] + 1;
                par[u] = v;
                col[u] = col[v];
                Q.push(u);
            } else if (col[u] != col[v]) {
                cout << "Possible\n";
                Print(u, par);
                par[u] = v;
                Print(u, par);
                return;
            }
    }
    cout << "Impossible\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> neigh(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (v != s)
            neigh[u].push_back(v);
    }
    Solve(n, neigh, s);
    return 0;
}
