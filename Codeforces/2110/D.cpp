#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

constexpr int Maxn = 200005;
constexpr int Inf = 1000000007;

int T;
int n, m;
int b[Maxn];
vector<ii> neigh[Maxn];
ll best[Maxn];

bool Solve(int x) {
    fill(best, best + n + 1, -1ll);
    best[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (best[i] == -1) continue;
        best[i] += b[i];
        for (auto &p: neigh[i])
            if (best[i] >= p.second && p.second <= x)
                best[p.first] = max(best[p.first], best[i]);
    }
    return best[n] >= 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            neigh[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int s, t, w;
            scanf("%d %d %d", &s, &t, &w);
            neigh[s].emplace_back(t, w);
        }
        int lef = 0, rig = Inf;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Solve(mid)) rig = mid - 1;
            else lef = mid + 1;
        }
        if (lef >= Inf) printf("-1\n");
        else printf("%d\n", lef);
    }
    return 0;
}