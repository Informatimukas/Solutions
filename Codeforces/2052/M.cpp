#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector<int> neigh[Maxn];
set<int> in[Maxn];
int my[Maxn];
vector<ii> res;

bool Traverse(int v, int p) {
    int has = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        if (Traverse(u, v))
            has = u;
    }
    if (has) {
        my[v] = has;
        my[has] = v;
        return false;
    }
    return true;
}

void Swap(int v, int u) {
    int colv = a[v];
    int colu = a[u];
    in[colv].erase(v);
    in[colv].insert(u);
    in[colu].erase(u);
    in[colu].insert(v);
    swap(a[u], a[v]);
    res.emplace_back(v, u);
}

void moveMe(int v) {
    if (my[v] == v) return;
    int u = my[v];
    int oth = *in[a[u]].begin() == u? *in[a[u]].rbegin(): *in[a[u]].begin();
    Swap(oth, v);
    moveMe(oth);
}

void Solve(int v) {
    if (v == my[v] || a[v] == a[my[v]])
        return;
    int oth = *in[a[v]].begin() == v? *in[a[v]].rbegin(): *in[a[v]].begin();
    Swap(my[v], oth);
    if (my[oth] != oth)
        Solve(oth);
    else {
        oth = *in[a[oth]].begin() == oth? *in[a[oth]].rbegin(): *in[a[oth]].begin();
        moveMe(oth);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        n *= 2;
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            in[i].clear();
            my[i] = i;
        }
        res.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            in[a[i]].insert(i);
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Traverse(1, 0);
        for (int i = 1; i <= n; i++)
            Solve(i);
        printf("%llu\n", res.size());
        for (auto &[a, b]: res)
            printf("%d %d\n", a, b);
    }
    return 0;
}