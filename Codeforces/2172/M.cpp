#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector neigh(n + 1, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    vector dist(n + 1, Inf);
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto& u : neigh[v])
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
    }
    vector res(k + 1, 0);
    for (int i = 1; i <= n; i++)
        res[a[i]] = max(res[a[i]], dist[i]);
    for (int i = 1; i <= k; i++)
        cout << res[i] << (i + 1 <= k ? ' ' : '\n');
    return 0;
}