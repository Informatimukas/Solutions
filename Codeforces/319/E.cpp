#include <bits/stdc++.h>
using namespace std;

struct UnionSet {
    vector<int> par, siz;
    vector<int> mn, mx;
    UnionSet(int n): par(n + 1), siz(n + 1, 1), mn(n + 1), mx(n + 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    void Union(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
};

void Remove(vector<vector<int>>& st, int v, int l, int r, int key, int node, UnionSet& U) {
    while (!st[v].empty()) {
        U.Union(st[v].back(), node);
        st[v].pop_back();
    }
    if (l < r) {
        int m = (l + r) / 2;
        if (key <= m)
            Remove(st, 2 * v, l, m, key, node, U);
        else Remove(st, 2 * v + 1, m + 1, r, key, node, U);
    }
}

void Add(vector<vector<int>>& st, int v, int l, int r, int a, int b, int node) {
    if (l == a && r == b)
        st[v].push_back(node);
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Add(st, 2 * v, l, m, a, min(m, b), node);
        if (m + 1 <= b)
            Add(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, node);
    }
}

bool Inside(int x, int b, const UnionSet& U) {
    return U.mn[b] < x && x < U.mx[b];
}

bool Solve(int a, int b, UnionSet& U) {
    a = U.getPar(a);
    b = U.getPar(b);
    return a == b || Inside(U.mn[a], b, U) || Inside(U.mx[a], b, U) ||
        U.mn[b] <= U.mn[a] && U.mx[a] <= U.mx[b] && U.siz[a] >= 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector queries(q, array<int, 3>());
    vector<int> un;
    int n = 0;
    for (auto& x : queries) {
        for (auto& y : x)
            cin >> y;
        if (x[0] == 1) {
            un.push_back(x[1]);
            un.push_back(x[2]);
            n++;
        }
    }
    ranges::sort(un);
    un.erase(ranges::unique(un).begin(), un.end());
    UnionSet U(n);
    vector st(4 * un.size(), vector<int>());
    n = 0;
    for (auto& x : queries)
        if (x[0] == 1) {
            n++;
            auto lef = distance(un.begin(), ranges::lower_bound(un, x[1]));
            auto rig = distance(un.begin(), ranges::lower_bound(un, x[2]));
            U.mn[n] = lef;
            U.mx[n] = rig;
            Remove(st, 1, 0, un.size() - 1, lef, n, U);
            Remove(st, 1, 0, un.size() - 1, rig, n, U);
            int root = U.getPar(n);
            int mn = U.mn[root], mx = U.mx[root];
            if (mn + 1 <= mx - 1)
                Add(st, 1, 0, un.size() - 1, mn + 1, mx - 1, n);
        } else cout << (Solve(x[1], x[2], U) ? "YES" : "NO") << "\n";
    return 0;
}