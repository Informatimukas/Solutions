#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Maxk = 20;

struct node {
    ll dist{0};
    int L{0};
    vector<int> P;
    vector<ii> neigh;
    int lef{0};
    node(): P(Maxk, 0) {}
};

struct smallNode {
    bool on{false};
    set<int> neigh;
    int par{0};
};

struct smallTree {
    set<ii> existing;
    ll totDist{0};
    vector<smallNode> nodes;
    smallTree(int n): nodes(n + 1) {}
};

void Traverse(vector<node>& nodes, int v) {
    static int cur = 0;
    nodes[v].lef = ++cur;
    for (auto& [u, cost] : nodes[v].neigh) {
        if (u == nodes[v].P[0])
            continue;
        nodes[u].P[0] = v;
        nodes[u].L = nodes[v].L + 1;
        nodes[u].dist = nodes[v].dist + cost;
        Traverse(nodes, u);
    }
}

int getLCA(const vector<node>& nodes, int a, int b) {
    if (nodes[a].L < nodes[b].L)
        swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[a].L - (1 << i) >= nodes[b].L)
            a = nodes[a].P[i];
    if (a == b)
        return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[a].P[i] != nodes[b].P[i])
            a = nodes[a].P[i], b = nodes[b].P[i];
    return nodes[a].P[0];
}

ll getDist(const vector<node>& nodes, int parent, int child) {
    return nodes[child].dist - nodes[parent].dist;
}

void addEdge(smallTree& tree, const vector<node>& nodes, int parent, int child) {
    if (parent)
        tree.totDist += getDist(nodes, parent, child);
    tree.nodes[parent].neigh.insert(child);
    tree.nodes[child].par = parent;
}

void removeEdge(smallTree& tree, const vector<node>& nodes, int parent, int child) {
    if (parent)
        tree.totDist -= getDist(nodes, parent, child);
    tree.nodes[parent].neigh.erase(child);
}

int changeOld(smallTree& tree, const vector<node>& nodes, int old, int nw) {
    int lca = getLCA(nodes, old, nw);
    ii key = {nodes[lca].lef, lca};
    if (!tree.existing.contains(key)) {
        old = tree.existing.lower_bound(key)->second;
        removeEdge(tree, nodes, tree.nodes[old].par, old);
        tree.existing.insert(key);
        addEdge(tree, nodes, tree.nodes[old].par, lca);
        addEdge(tree, nodes, lca, old);
    }
    return lca;
}

void Add(smallTree& tree, const vector<node>& nodes, int v) {
    ii key = {nodes[v].lef, v};
    tree.nodes[v].on = true;
    auto it = tree.existing.lower_bound(key);
    ii best = {0, 0};
    if (it != tree.existing.end()) {
        if (it->second == v)
            return;
        int cand = changeOld(tree, nodes, it->second, v);
        best = max(best, {nodes[cand].L, cand});
    }
    it = tree.existing.upper_bound(key);
    if (it != tree.existing.begin()) {
        --it;
        if (it->second == v)
            return;
        int cand = changeOld(tree, nodes, it->second, v);
        best = max(best, {nodes[cand].L, cand});
    }
    if (best.second != v) {
        tree.existing.insert({nodes[v].lef, v});
        addEdge(tree, nodes, best.second, v);
    }
}

void removeLeaf(smallTree& tree, const vector<node>& nodes, int v) {
    if (v == 0)
        return;
    if (tree.nodes[v].on || !tree.nodes[v].neigh.empty())
        return;
    tree.existing.erase({nodes[v].lef, v});
    removeEdge(tree, nodes, tree.nodes[v].par, v);
    removeLeaf(tree, nodes, tree.nodes[v].par);
}

void Remove(smallTree& tree, const vector<node>& nodes, int v) {
    tree.nodes[v].on = false;
    removeLeaf(tree, nodes, v);
    while (true) {
        if (tree.nodes[0].neigh.empty())
            break;
        int root = *tree.nodes[0].neigh.begin();
        if (tree.nodes[root].on || tree.nodes[root].neigh.size() > 1)
            break;
        tree.existing.erase({nodes[root].lef, root});
        removeEdge(tree, nodes, 0, root);
        if (tree.nodes[root].neigh.empty())
            break;
        int nroot = *tree.nodes[root].neigh.begin();
        removeEdge(tree, nodes, root, nroot);
        addEdge(tree, nodes, 0, nroot);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].neigh.emplace_back(b, c);
        nodes[b].neigh.emplace_back(a, c);
    }
    Traverse(nodes, 1);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            nodes[i].P[j] = nodes[nodes[i].P[j - 1]].P[j - 1];
    smallTree tree(n);
    int q;
    cin >> q;
    while (q--) {
        char typ;
        cin >> typ;
        if (typ == '+') {
            int v;
            cin >> v;
            Add(tree, nodes, v);
        } else if (typ == '-') {
            int v;
            cin >> v;
            Remove(tree, nodes, v);
        } else cout << tree.totDist << endl;
    }
    return 0;
}
