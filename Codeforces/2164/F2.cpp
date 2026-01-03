// Next steps: to find the value for the vertex v, we select the minimal value
// in its range as long as it has some a_u = 0.
// Then we cut a virtual tree from such vertices and compute the number
// of values obtained as well as the number of ways (using binomials).
// The solution below is missing Solve() function.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using ill = pair<int, ll>;

constexpr int Maxk = 20;
constexpr int Inf = 1000000000;
constexpr int mod = 998244353;

struct node {
    vector<int> neigh;
    int L{0};
    array<int, Maxk> P{};
    int lef{0}, rig{0};
    int a{0};
};

struct segNode {
    int delt{0};
    array<int, 3> mn{};
};

void Traverse(vector<node>& nodes, int v, int& cur, vector<int>& hasLef) {
    nodes[v].lef = ++cur;
    hasLef[nodes[v].lef] = v;
    for (auto& u : nodes[v].neigh) {
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u, cur, hasLef);
    }
    nodes[v].rig = cur;
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

array<int, 3> Union(const array<int, 3>& a, const array<int, 3>& b) {
    if (a[0] != b[0])
        return a[0] < b[0] ? a : b;
    return a[1] > b[1] ? a : b;
}

void downOn(segNode& nod, int d) {
    nod.delt += d;
    nod.mn[0] += d;
}

void Down(vector<segNode>& st, int v) {
    if (st[v].delt) {
        downOn(st[2 * v], st[v].delt);
        downOn(st[2 * v + 1], st[v].delt);
        st[v].delt = 0;
    }
}

void Create(vector<segNode>& st, int v, int l, int r, const vector<node>& nodes,
    const vector<int>& hasLef) {
    if (l == r) {
        int vertex = hasLef[l];
        st[v].mn = {nodes[vertex].a, nodes[vertex].L, vertex};
    } else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m, nodes, hasLef);
        Create(st, 2 * v + 1, m + 1, r, nodes, hasLef);
        st[v].mn = Union(st[2 * v].mn, st[2 * v + 1].mn);
    }
}

void Update(vector<segNode>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        downOn(st[v], -1);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b);
        st[v].mn = Union(st[2 * v].mn, st[2 * v + 1].mn);
    }
}

array<int, 3> Get(vector<segNode>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v].mn;
    Down(st, v);
    int m = (l + r) / 2;
    if (b <= m)
        return Get(st, 2 * v, l, m, a, b);
    if (m + 1 <= a)
        return Get(st, 2 * v + 1, m + 1, r, a, b);
    return Union(Get(st, 2 * v, l, m, a, m),
        Get(st, 2 * v + 1, m + 1, r, m + 1, b));
}

void Remove(vector<segNode>& st, int v, int l, int r, int elim) {
    if (l == r)
        st[v].mn = {Inf, 0, 0};
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (st[2 * v].mn[2] == elim)
            Remove(st, 2 * v, l, m, elim);
        else Remove(st, 2 * v + 1, m + 1, r, elim);
        st[v].mn = Union(st[2 * v].mn, st[2 * v + 1].mn);
    }
}

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); }

ll C(int n, int k, const vector<ll>& fac, const vector<ll>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

ill Solve(int v, const vector<node>& nodes, vector<segNode>& st, const vector<ll>& fac,
    const vector<ll>& ifac) {
    ll ways = 1;
    vector<array<int, 3>> seq;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<node> nodes(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> nodes[i].P[0];
            nodes[nodes[i].P[0]].neigh.push_back(i);
        }
        vector<int> hasLef(n + 1);
        int cur = 0;
        Traverse(nodes, 1, cur, hasLef);
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                nodes[i].P[j] = nodes[nodes[i].P[j - 1]].P[j - 1];
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].a;
        vector<segNode> st(4 * n);
        Create(st, 1, 1, n, nodes, hasLef);
        vector<ll> fac(n + 1), ifac(n + 1);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            ifac[i] = Inv(fac[i]);
        }

    }
    return 0;
}