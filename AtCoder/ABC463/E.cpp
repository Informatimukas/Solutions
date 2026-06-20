#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;
using lli = pair<ll, int>;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<ii>> neigh(n + 1);
    vector<int> X(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        neigh[a].emplace_back(b, c);
        neigh[b].emplace_back(a, c);
    }
    for (int i = 1; i <= n; i++)
        cin >> X[i];
    vector dist(n + 1, Inf);
    dist[1] = 0;
    priority_queue<lli, vector<lli>, greater<>> Q;
    Q.push({dist[1], 1});
    while (!Q.empty()) {
        int v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (dist[v] != d)
            continue;
        if (v == 0) {
            for (int i = 1; i <= n; i++)
                if (d + X[i] + y < dist[i]) {
                    dist[i] = d + X[i] + y;
                    Q.push({dist[i], i});
                }
            continue;
        }
        if (d + X[v] < dist[0]) {
            dist[0] = d + X[v];
            Q.push({dist[0], 0});
        }
        for (auto& [u, add] : neigh[v])
            if (d + add < dist[u]) {
                dist[u] = d + add;
                Q.push({dist[u], u});
            }
    }
    for (int i = 2; i <= n; i++)
        cout << dist[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
