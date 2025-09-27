#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int mod = 998244353;
constexpr int Maxk = 20;

struct UnionSet {
    vector<int> par, siz;
    UnionSet(int n): par(n + 1), siz(n + 1, 0) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
    bool unionSet(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return false;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        return true;
    }
};

struct Tree {
    vector<vector<int>> neigh;
    vector<vector<int>> P;
    vector<int> L;
    vector<int> st;
    Tree(int n): neigh(n + 1), P(n + 1, vector(Maxk, 0)), L(n + 1, 0),
        st(n + 1, 0) {}
};

void Traverse(int v, Tree& tree) {
    for (auto& u : tree.neigh[v]) {
        if (u == tree.P[v][0])
            continue;
        tree.P[u][0] = v;
        tree.L[u] = tree.L[v] + 1;
        Traverse(u, tree);
    }
}

int getLCA(int a, int b, const Tree& tree) {
    if (tree.L[a] < tree.L[b])
        swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (tree.L[a] - (1 << i) >= tree.L[b])
            a = tree.P[a][i];
    if (a == b)
        return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (tree.P[a][i] != tree.P[b][i])
            a = tree.P[a][i], b = tree.P[b][i];
    return tree.P[a][0];
}

optional<int> Merge(int a, int b) {
    if (a == -1)
        return {b};
    if (b == -1 || a == b)
        return {a};
    return {};
}

optional<int> getRes(int v, Tree& tree, vector<int>& A) {
    int res = 0;
    for (auto& u : tree.neigh[v]) {
        if (u == tree.P[v][0])
            continue;
        auto got = getRes(u, tree, A);
        if (!got)
            return {};
        res += *got;
        if (tree.st[u]) {
            auto nd = Merge(A[v], A[u]);
            if (!nd)
                return {};
            A[v] = *nd;
            tree.st[v] += tree.st[u];
        }
    }
    if (tree.st[v] == 0 && A[v] == -1)
        res++;
    return {res};
}

int Solve(Tree& tree, const vector<ii>& queries, vector<int>& A, int V) {
    for (auto& [a, b] : queries) {
        int lca = getLCA(a, b, tree);
        tree.st[a]++;
        tree.st[b]++;
        tree.st[lca] -= 2;
        if ((tree.L[a] + tree.L[b]) % 2 == 0) {
            auto nd = Merge(A[a], 0);
            if (!nd) return 0;
            A[a] = *nd;
        }
    }
    auto cnt = getRes(1, tree, A);
    if (!cnt)
        return 0;
    int tims = *cnt;
    int res = 1;
    while (tims--)
        res = static_cast<ll>(res) * V % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, V;
        cin >> n >> m >> V;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<ii> queries;
        UnionSet us(n);
        Tree t(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            if (us.unionSet(a, b)) {
                t.neigh[a].push_back(b);
                t.neigh[b].push_back(a);
            } else queries.emplace_back(a, b);
        }
        Traverse(1, t);
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                t.P[i][j] = t.P[t.P[i][j - 1]][j - 1];
        cout << Solve(t, queries, a, V) << '\n';
    }
    return 0;
}
