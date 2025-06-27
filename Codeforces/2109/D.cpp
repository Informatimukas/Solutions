#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

constexpr int Maxn = 200005;
constexpr int Inf = 2000000007;

int T;
int n, m, l;
int best[2];
int dist[Maxn][2];
vector<int> neigh[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &l);
        best[0] = 0;
        best[1] = -Inf;
        for (int i = 0; i < l; i++) {
            int x; scanf("%d", &x);
            if (x % 2 == 0) {
                best[0] += x;
                best[1] += x;
            } else {
                int wth[2] = {best[1] + x, best[0] + x};
                for (int j = 0; j < 2; j++)
                    if (wth[j] > best[j])
                        best[j] = wth[j];
            }
        }
        for (int i = 1; i <= n; i++) {
            fill_n(dist[i], 2, Inf);
            neigh[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        dist[1][0] = 0;
        priority_queue<iii, vector<iii>, greater<>> Q;
        Q.push({dist[1][0], {1, 0}});
        while (!Q.empty()) {
            int d = Q.top().first;
            ii p = Q.top().second;
            Q.pop();
            if (d != dist[p.first][p.second])
                continue;
            for (int i = 0; i < neigh[p.first].size(); i++) {
                int cand = d + 1;
                ii u = {neigh[p.first][i], 1 - p.second};
                if (cand < dist[u.first][u.second]) {
                    dist[u.first][u.second] = cand;
                    Q.push({cand, u});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int num = 0;
            for (int j = 0; j < 2; j++)
                if (dist[i][j] <= best[j])
                    num = 1;
            printf("%d", num);
        }
        printf("\n");
    }
    return 0;
}
