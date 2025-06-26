#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
bool vis[Maxn], st[Maxn];
vector<ii> neigh[Maxn];
int E[Maxn][2];

void Set(int v, int ind, int wh) {
    if (E[ind][wh] != v)
        swap(E[ind][0], E[ind][1]);
}

void traverseSet(int v, int pind, int wh) {
    st[v] = vis[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        auto &[u, ind] = neigh[v][i];
        if (ind == pind) continue;
        if (!vis[u]) {
            Set(v, ind, wh);
            traverseSet(u, ind, wh);
        } else if (st[u])
            Set(v, ind, wh);
    }
    st[v] = false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            vis[i] = st[i] = false;
            neigh[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &E[i][0]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &E[i][1]);
            neigh[E[i][0]].emplace_back(E[i][1], i);
            neigh[E[i][1]].emplace_back(E[i][0], i);
        }
        for (int i = 1; i <= 2 * n; i++) if (!vis[i]) {
            int wh = 0;
            for (auto [u, ind] : neigh[i]) {
                if (vis[u]) continue;
                Set(i, ind, wh);
                traverseSet(u, ind, wh);
                wh = 1;
            }
        }
        set<int> S[2];
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 2; j++)
                S[j].insert(E[i][j]);
        printf("%d\n", S[0].size() + S[1].size());
        for (int i = 1; i <= n; i++)
            printf("%d%c", E[i][0], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; i++)
            printf("%d%c", E[i][1], i == n ? '\n' : ' ');
    }
    return 0;
}