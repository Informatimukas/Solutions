#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;
constexpr int Inf = 1000000007;

int T;
int n, m;
vector<ii> neigh[Maxn];
int dist1[Maxn], distn[Maxn];

void Dijkstra(int v, int dist[]) {
    fill_n(dist, n + 1, Inf);
    dist[v] = 0;
    priority_queue<ii, vector<ii>, greater<>> Q;
    Q.push({ 0, v });
    while (!Q.empty()) {
        int d = Q.top().first;
        v = Q.top().second;
        Q.pop();
        if (d > dist[v]) continue;
        for (auto &e : neigh[v]) {
            int w = e.second;
            if (max(d, w) < dist[e.first]) {
                dist[e.first] = max(d, w);
                Q.emplace( dist[e.first], e.first );
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            neigh[a].emplace_back(b, w);
            neigh[b].emplace_back(a, w);
        }
        Dijkstra(1, dist1);
        Dijkstra(n, distn);
        int res = 2 * Inf;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < neigh[i].size(); j++) {
                int u = neigh[i][j].first;
                int mx = max({dist1[i], distn[u], neigh[i][j].second});
                res = min(res, mx + neigh[i][j].second);
            }
        printf("%d\n", res);
    }
    return 0;
}