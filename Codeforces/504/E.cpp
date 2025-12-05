// Next steps: the solution has complexity of O(logn*(n+q)) which seems to be
// sufficient. Implementation gets TLE though. Make improvements to make this faster.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxk = 20;

struct node {
    char let;
    vector<int> neigh;
    int L{0};
    array<int, Maxk> P{};
    int H{0}, R{0};
    vector<array<int, 3>> requests;
};

struct hasher {
    int mod;
    vector<int> pw, ipw;
    bool Prime(int x)
    {
        if (x <= 1) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }
    int toPower(int a, int p)
    {
        int res = 1;
        while (p) {
            if (p & 1)
                res = static_cast<ll>(res) * a % mod;
            p >>= 1;
            a = static_cast<ll>(a) * a % mod;
        }
        return res;
    }
    int Inv(int x) { return toPower(x, mod - 2); }
    hasher() = default;
    hasher(int n) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        mod = uniform_int_distribution(100000000, 1000000000)(rng);
        int arg = uniform_int_distribution(1000000, 10000000)(rng);
        while (!Prime(mod))
            mod++;
        while (!Prime(arg))
            arg++;
        int iarg = Inv(arg);
        pw.resize(n + 1);
        ipw.resize(n + 1);
        pw[0] = ipw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = static_cast<ll>(pw[i - 1]) * arg % mod;
            ipw[i] = static_cast<ll>(ipw[i - 1]) * iarg % mod;
        }
    }
    int addH(int a, int b, int blen) {
        return (static_cast<ll>(a) * pw[blen] + b) % mod;
    }
    int addH(int oldh, char ch) {
        return addH(oldh, ch - 'a' + 1, 1);
    }
    int addR(int oldr, char ch, int lvl) {
        return (oldr + static_cast<ll>(ch - 'a' + 1) * pw[lvl]) % mod;
    }
    int cutH(int my, int sub, int difLvl) {
        return (my - static_cast<ll>(sub) * pw[difLvl] % mod + mod) % mod;
    }
    int cutR(int my, int sub, int lcaLvl) {
        return static_cast<ll>((my - sub + mod) % mod) * ipw[lcaLvl] % mod;
    }
};

struct query {
    int a, b, c, d;
    int lca1, lca2;
    int lef, rig, mid;
    array<int, 2> got;
};

void Traverse(vector<node>& nodes, int v, hasher& h) {
    int p = nodes[v].P[0];
    nodes[v].L = nodes[p].L + 1;
    for (int j = 1; j < Maxk; j++)
        nodes[v].P[j] = nodes[nodes[v].P[j - 1]].P[j - 1];
    nodes[v].H = h.addH(nodes[p].H, nodes[v].let);
    nodes[v].R = h.addR(nodes[p].R, nodes[v].let, nodes[v].L);
    for (auto& u : nodes[v].neigh) {
        if (u == p)
            continue;
        nodes[u].P[0] = v;
        Traverse(nodes, u, h);
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

int getLen(const vector<node>& nodes, int a, int b, int lca) {
    return nodes[a].L + nodes[b].L - 2 * nodes[lca].L + 1;
}

array<int, 2> getVertex(const vector<node>& nodes, int a, int b, int lca, int ind) {
    if (nodes[a].L - nodes[lca].L + 1 >= ind)
        return {a, nodes[a].L - (ind - 1)};
    ind -= (nodes[a].L - nodes[lca].L + 1);
    return {b, nodes[lca].L + ind};
}

int getHash(const vector<node>& nodes, int a, int b, int lca, int ind, int got, hasher& h) {
    if (nodes[a].L - nodes[lca].L + 1 >= ind)
        return h.cutR(nodes[a].R, nodes[nodes[got].P[0]].R, nodes[got].L);
    int fir = h.cutR(nodes[a].R, nodes[nodes[lca].P[0]].R, nodes[lca].L);
    int sec = h.cutH(nodes[got].H, nodes[lca].H, nodes[got].L - nodes[lca].L);
    return h.addH(fir, sec, nodes[got].L - nodes[lca].L);
}

void getImportant(vector<node>& nodes, int v, vector<query>& queries, vector<int>& seq) {
    seq[nodes[v].L] = v;
    for (auto& [lvl, ind, ind2] : nodes[v].requests)
        queries[ind].got[ind2] = seq[lvl];
    nodes[v].requests.clear();
    for (auto& u : nodes[v].neigh) {
        if (u == nodes[v].P[0])
            continue;
        getImportant(nodes, u, queries, seq);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
        nodes[i].let = s[i - 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        nodes[v].neigh.push_back(u);
        nodes[u].neigh.push_back(v);
    }
    hasher h(n);
    Traverse(nodes, 1, h);
    int m;
    cin >> m;
    vector<query> queries(m);
    for (int i = 0; i < m; i++) {
        auto& q = queries[i];
        cin >> q.a >> q.b >> q.c >> q.d;
        q.lca1 = getLCA(nodes, q.a, q.b);
        q.lca2 = getLCA(nodes, q.c, q.d);
        q.lef = 1;
        q.rig = min(getLen(nodes, q.a, q.b, q.lca1), getLen(nodes, q.c, q.d, q.lca2));
    }
    vector<int> seq(n + 1);
    for (int j = 0; j < Maxk; j++) {
        for (int i = 0; i < m; i++) {
            auto& q = queries[i];
            if (q.lef <= q.rig) {
                q.mid = (q.lef + q.rig) / 2;
                auto [v1, lvl1] = getVertex(nodes, q.a, q.b, q.lca1, q.mid);
                nodes[v1].requests.push_back({lvl1, i, 0});
                auto [v2, lvl2] = getVertex(nodes, q.c, q.d, q.lca2, q.mid);
                nodes[v2].requests.push_back({lvl2, i, 1});
            }
        }
        getImportant(nodes, 1, queries, seq);
        for (int i = 0; i < m; i++) {
            auto& q = queries[i];
            if (q.lef <= q.rig) {
                int hash1 = getHash(nodes, q.a, q.b, q.lca1, q.mid, q.got[0], h);
                int hash2 = getHash(nodes, q.c, q.d, q.lca2, q.mid, q.got[1], h);
                if (hash1 == hash2)
                    q.lef = q.mid + 1;
                else q.rig = q.mid - 1;
            }
        }
    }
    for (auto& q : queries)
        cout << q.rig << "\n";
    return 0;
}