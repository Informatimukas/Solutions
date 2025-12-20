#include <bits/stdc++.h>
using namespace std;

constexpr int Maxk = 20;

struct edge {
    int u{0}, v{0};
    bool bridge{false};
};

struct node {
    vector<pair<int, edge*>> neigh;
    int tim{0}, low{0};
};

struct cycleEdge {
    int origu{0}, origv{0};
    int u{0}, v{0};
    int getOrig(int x) const { return x == u ? origu : origv; }
};

struct cycleNode {
    vector<pair<int, cycleEdge*>> neigh;
    int rep{0}, con{0}, siz{0}, value{0}, L{0};
    array<int, Maxk> P{};
};

struct unionSet {
    vector<int> par, siz, value;
    unionSet(int n) : par(n + 1), siz(n + 1, 1), value(n + 1) {
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
        value[a] += value[b];
        par[b] = a;
    }
};

void findBridges(vector<node>& nodes, int v, int p) {
    static int cur = 0;
    nodes[v].tim = nodes[v].low = ++cur;
    for (auto& [u, e] : nodes[v].neigh) {
        if (u == p)
            continue;
        if (!nodes[u].tim) {
            findBridges(nodes, u, v);
            nodes[v].low = min(nodes[v].low, nodes[u].low);
            if (nodes[v].tim < nodes[u].low)
                e->bridge = true;
        } else nodes[v].low = min(nodes[v].low, nodes[u].tim);
    }
}

void Traverse(vector<cycleNode>& nodes, unionSet& U, int v) {
    nodes[v].siz = U.value[v];
    for (auto& [u, e] : nodes[v].neigh) {
        if (u == nodes[v].P[0])
            continue;
        nodes[u].rep = e->getOrig(u);
        nodes[u].con = e->getOrig(v);
        nodes[u].value = nodes[v].value + (nodes[u].con == nodes[v].rep ? 0 : U.value[v]);
        nodes[u].L = nodes[v].L + 1;
        nodes[u].P[0] = v;
        Traverse(nodes, U, u);
    }
}

int getLCA(const vector<cycleNode>& nodes, int v, int u) {
    if (nodes[v].L < nodes[u].L)
        swap(v, u);
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[v].L - (1 << i) >= nodes[u].L)
            v = nodes[v].P[i];
    if (v == u)
        return v;
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[v].P[i] != nodes[u].P[i])
            v = nodes[v].P[i], u = nodes[u].P[i];
    return nodes[v].P[0];
}

int goUp(const vector<cycleNode>& nodes, int v, int lca) {
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[v].L - (1 << i) > nodes[lca].L)
            v = nodes[v].P[i];
    return v;
}

int getValue(const vector<cycleNode>& nodes, int& a, int compa, int lca) {
    int res = 0;
    if (compa != lca) {
        if (a != nodes[compa].rep)
            res += nodes[compa].siz;
        int nxta = goUp(nodes, compa, lca);
        res += nodes[compa].value - nodes[nxta].value;
        a = nodes[nxta].con;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<node> nodes(n + 1);
    vector<edge> edges(m);
    for (auto& e : edges) {
        cin >> e.u >> e.v;
        nodes[e.u].neigh.emplace_back(e.v, &e);
        nodes[e.v].neigh.emplace_back(e.u, &e);
    }
    findBridges(nodes, 1, 0);
    unionSet U(n);
    for (auto& e : edges)
        if (!e.bridge) {
            U.Union(e.u, e.v);
            U.value[U.getPar(e.u)]++;
        }
    vector<cycleEdge> cycleEdges;
    for (auto& e : edges) {
        int nwu = U.getPar(e.u), nwv = U.getPar(e.v);
        if (nwu == nwv)
            continue;
        cycleEdges.emplace_back(e.u, e.v, nwu, nwv);
    }
    vector<cycleNode> cycleNodes(n + 1);
    for (auto& e : cycleEdges) {
        cycleNodes[e.u].neigh.emplace_back(e.v, &e);
        cycleNodes[e.v].neigh.emplace_back(e.u, &e);
    }
    Traverse(cycleNodes, U, U.getPar(1));
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            cycleNodes[i].P[j] = cycleNodes[cycleNodes[i].P[j - 1]].P[j - 1];
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int compa = U.getPar(a), compb = U.getPar(b);
        int lca = getLCA(cycleNodes, compa, compb);
        int res = getValue(cycleNodes, a, compa, lca) +
            getValue(cycleNodes, b, compb, lca);
        if (a != b)
            res += cycleNodes[lca].siz;
        cout << res << "\n";
    }
    return 0;
}
