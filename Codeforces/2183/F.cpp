#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int mod = 998244353;

struct node {
    vector<int> neigh;
    int L{0};
    int siz{1};
    int P{0};
    int res{0};
};

void Traverse(vector<node>& nodes, int v, int p) {
    nodes[v].P = p;
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u, v);
        nodes[v].siz += nodes[u].siz;
    }
}

void Mark2(const vector<node>& nodes, int v, int p, int oth, int value, vector<vector<int>>& lca,
    vector<ii>& seq) {
    int v1 = oth, v2 = v;
    if (v1 > v2)
        swap(v1, v2);
    seq.emplace_back(v1, v2);
    lca[v1][v2] = value;
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        Mark2(nodes, u, v, oth, value, lca, seq);
    }
}

void Mark1(const vector<node>& nodes, int v, int p, int oth, int value, vector<vector<int>>& lca,
    vector<ii>& seq) {
    Mark2(nodes, oth, value, v, value, lca, seq);
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        Mark1(nodes, u, v, oth, value, lca, seq);
    }
}

void Mark(const vector<node>& nodes, int v, int p, vector<vector<int>>& lca, vector<ii>& seq) {
    for (int i = 0; i < nodes[v].neigh.size(); ++i) {
        int u1 = nodes[v].neigh[i];
        if (u1 == p)
            continue;
        Mark(nodes, u1, v, lca, seq);
        for (int j = i + 1; j < nodes[v].neigh.size(); ++j) {
            int u2 = nodes[v].neigh[j];
            if (u2 == p)
                continue;
            Mark1(nodes, u1, v, u2, v, lca, seq);
        }
    }
    Mark2(nodes, v, p, v, v, lca, seq);
}

void Collect(vector<node>& nodes, int v, int p) {
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        Collect(nodes, u, v);
        nodes[v].res = (nodes[v].res + nodes[u].res) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        Traverse(nodes, 1, 0);
        vector lca(n + 1, vector<int>(n + 1));
        vector<ii> seq;
        Mark(nodes, 1, 0, lca, seq);
        vector res(n + 1, vector<int>(n + 1));
        for (auto& [u, v] : seq) {
            cout << "u = " << u << ", v = " << v << ", lca = " << lca[u][v] << endl;
            if (a[u - 1] == a[v - 1])
                res[u][v] = (res[u][v] + (u == v ? 1 : 2)) % mod;
            cout << "res[" << u << ", v = " << v << "] = " << res[u][v] << endl;
            nodes[lca[u][v]].res = (nodes[lca[u][v]].res + res[u][v]) % mod;
            int pu = nodes[u].P, pv = nodes[v].P;
            if (pu && pv) {
                if (pu > pv)
                    swap(pu, pv);
                if (a[pu] == a[pv])
                    res[pu][pv] = (res[pu][pv] + res[u][v]) % mod;
            }
        }
        for (int i = 1; i <= n; i++)
            cout << nodes[i].res << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
