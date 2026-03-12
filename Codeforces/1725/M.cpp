#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using llii = pair<ll, ii>;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector neigh(n + 1, vector<vector<ii>>(2));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        neigh[u][0].emplace_back(v, w);
        neigh[v][1].emplace_back(u, w);
    }
    vector dist(n + 1, vector(2, Inf));
    dist[1][0] = 0;
    priority_queue<llii, vector<llii>, greater<>> Q;
    Q.push({0, {1, 0}});
    while (!Q.empty()) {
        ii v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (dist[v.first][v.second] != d)
            continue;
        for (auto [u, add] : neigh[v.first][v.second]) {
            ii nxt = {u, v.second};
            ll cand = d + add;
            if (cand < dist[nxt.first][nxt.second]) {
                dist[nxt.first][nxt.second] = cand;
                Q.emplace(cand, nxt);
            }
        }
        if (v.second == 0) {
            ii nxt = {v.first, 1};
            ll cand = d;
            if (cand < dist[nxt.first][nxt.second]) {
                dist[nxt.first][nxt.second] = cand;
                Q.emplace(cand, nxt);
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << (dist[i][1] < Inf ? dist[i][1] : -1ll) << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
