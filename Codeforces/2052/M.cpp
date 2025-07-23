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

int getOth(int v) { return *in[a[v]].begin() == v? *in[a[v]].rbegin(): *in[a[v]].begin(); }

ii getEdges(int col) {
    ii res = {0, 0};
    int v = *in[col].begin();
    int u = *in[col].rbegin();
    if (my[v] != v) {
        res.first++;
        res.second = a[my[v]];
    }
    if (my[u] != u) {
        res.first++;
        res.second = a[my[u]];
    }
    return res;
}

int getFirst(int col) {
    int v = *in[col].begin();
    int u = *in[col].rbegin();
    return my[v] != v? v: u;
}

int getLast(int col) {
    int v = *in[col].begin();
    int u = *in[col].rbegin();
    return my[v] == v? v: u;
}

int getEnd(int cur, int prv) {
    ii got = getEdges(cur);
    if (got.first == 1)
        return cur;
    int v = *in[cur].begin();
    int u = *in[cur].rbegin();
    return getEnd(a[my[v]] == prv? a[my[u]]: a[my[v]], cur);
}

void Solve(int v) {
    if (v == my[v] || a[v] == a[my[v]])
        return;
    int oth = getOth(v);
    Swap(my[v], oth);
    Solve(oth);
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
        for (int i = 1; i <= n / 2; i++) {
            ii st = getEdges(i);
            if (st.first == 1) {
                int en = getEnd(st.second, i);
                int f = getFirst(i);
                Swap(f, getLast(en));
                Solve(f);
            }
        }
        for (int i = 1; i <= n; i++)
            Solve(i);
        printf("%llu\n", res.size());
        for (auto &[a, b]: res)
            printf("%d %d\n", a, b);
    }
    return 0;
}