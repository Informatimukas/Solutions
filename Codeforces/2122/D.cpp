#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

constexpr int Maxn = 5005;
constexpr int Inf = 1000000000;

int T;
int n, m;
vector<int> neigh[Maxn];
int dist[2 * Maxn][Maxn];

ii Solve() {
    for (int i = 0; i <= 2 * n; i++)
        fill_n(dist[i], n + 1, Inf);
    ii best = {Inf, Inf};
    dist[0][1] = 0;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 1; j <= n; j++) if (dist[i][j] < Inf) {
            if (j == n)
                best = min(best, {i, dist[i][j]});
            if (i == 2 * n)
                continue;
            dist[i + 1][j] = min(dist[i + 1][j], dist[i][j] + 1);
            int nxt = neigh[j][i % neigh[j].size()];
            dist[i + 1][nxt] = min(dist[i + 1][nxt], dist[i][j]);
        }
    return best;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        ii res = Solve();
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}