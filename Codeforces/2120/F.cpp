#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxb = 62;
constexpr int Maxn = 602;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int T;
int n, k;
int N;
vector<int> neigh[Maxn];
bool E[Maxn][Maxn];
ll my[Maxn], mask[Maxn];
int cur, tim[Maxn], low[Maxn];
int comp, scc[Maxn];
bool onStack[Maxn];
vector<int> S;

int Not(int v) { return v <= n? v + n: v - n; }

void SCC(int v) {
    tim[v] = low[v] = ++cur;
    S.push_back(v);
    onStack[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (!low[u]) {
            SCC(u);
            low[v] = min(low[v], low[u]);
        } else if (onStack[u])
            low[v] = min(low[v], tim[u]);
    }
    if (low[v] == tim[v]) {
        comp++;
        int w;
        do {
            w = S.back();
            S.pop_back();
            onStack[w] = false;
            scc[w] = comp;
        } while (w != v);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        N = 2 * n;
        for (int i = 1; i <= N; i++) {
            neigh[i].clear();
            tim[i] = low[i] = 0;
        }
        cur = 0;
        comp = 0;
        while (k--) {
            for (int i = 1; i <= n; i++) {
                fill_n(E[i] + 1, n, false);
                my[i] = uniform_int_distribution<ll>(1, (1ll << Maxb) - 1)(rng);
                mask[i] = 0;
            }
            int m; scanf("%d", &m);
            while (m--) {
                int a, b; scanf("%d %d", &a, &b);
                E[a][b] = E[b][a] = true;
                mask[a] ^= my[b];
                mask[b] ^= my[a];
            }
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    if (E[i][j] && (mask[i] ^ my[j]) == (mask[j] ^ my[i])) {
                        neigh[i].push_back(Not(j));
                        neigh[j].push_back(Not(i));
                    } else if (!E[i][j] && mask[i] == mask[j]) {
                        neigh[Not(i)].push_back(j);
                        neigh[Not(j)].push_back(i);
                    }
        }
        for (int i = 1; i <= N; i++)
            if (!tim[i])
                SCC(i);
        bool good = true;
        for (int i = 1; i <= n; i++)
            if (scc[i] == scc[Not(i)]) {
                good = false;
                break;
            }
        printf("%s\n", good? "Yes" : "No");
    }
    return 0;
}
