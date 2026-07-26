#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

struct SegTree {
    int n{0};
    vector<ll> mx, fl;
    void Union(int v) {
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
    void downOn(int v, ll delt) {
        mx[v] += delt;
        fl[v] += delt;
    }
    void Down(int v) {
        if (fl[v]) {
            downOn(2 * v, fl[v]);
            downOn(2 * v + 1, fl[v]);
            fl[v] = 0;
        }
    }
    void Create(int v, int l, int r, const vector<int>& a) {
        if (l == r)
            mx[v] = a[l];
        else {
            int m = (l + r) / 2;
            Create(2 * v, l, m, a);
            Create(2 * v + 1, m + 1, r, a);
            Union(v);
        }
    }
    SegTree() = default;
    SegTree(const vector<int>& a): n(a.size()), mx(8 * n), fl(8 * n) {
        Create(1, 0, n - 1, a);
    }
    void Update(int v, int l, int r, int a, int b, ll delt) {
        if (l == a && r == b)
            downOn(v, delt);
        else {
            Down(v);
            int m = (l + r) / 2;
            if (a <= m)
                Update(2 * v, l, m, a, min(m, b), delt);
            if (m + 1 <= b)
                Update(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
            Union(v);
        }
    }
    void Update(int l, int r, ll delt) { Update(1, 0, n - 1, l, r, delt); }
    ll Get(int v, int l, int r, int a, int b) {
        if (l == a && r == b)
            return mx[v];
        Down(v);
        int m = (l + r) / 2;
        if (b <= m)
            return Get(2 * v, l, m, a, b);
        if (m + 1 <= a)
            return Get(2 * v + 1, m + 1, r, a, b);
        return max(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
    ll Get(int l, int r) { return Get(1, 0, n - 1, l, r); }
};

struct node {
    int a;
    SegTree st;
    int p{0};
    int head, id;
    int leaf;
    int cnt;
    vector<int> neigh;
};

int Count(int v, vector<node>& nodes) {
    nodes[v].cnt = 1;
    if (nodes[v].neigh.empty())
        return nodes[v].leaf = v;
    for (auto u : nodes[v].neigh) {
        int got = Count(u, nodes);
        nodes[v].cnt += nodes[u].cnt;
        if (!nodes[v].leaf)
            nodes[v].leaf = got;
    }
    return nodes[v].leaf;
}

void Traverse(int v, vector<node>& nodes, vector<int>& seq) {
    for (auto u : nodes[v].neigh)
        if (nodes[u].cnt <= nodes[v].cnt / 2) {
            vector tmp = {nodes[u].a};
            nodes[u].head = u;
            nodes[u].id = 0;
            Traverse(u, nodes, tmp);
        } else {
            nodes[u].head = nodes[v].head;
            nodes[u].id = nodes[v].id + 1;
            seq.push_back(nodes[u].a);
            Traverse(u, nodes, seq);
        }
    if (nodes[v].id == 0)
        nodes[v].st = SegTree(seq);
}

ll maxAll(int v, vector<node>& nodes) {
    ll mx = -Inf;
    while (v) {
        mx = max(mx, nodes[nodes[v].head].st.Get(0, nodes[v].id));
        v = nodes[nodes[v].head].p;
    }
    return mx;
}

void coverAll(int v, ll delt, vector<node>& nodes) {
    while (v) {
        nodes[nodes[v].head].st.Update(0, nodes[v].id, -delt);
        v = nodes[nodes[v].head].p;
    }
}

ll countFirst(int v, vector<node>& nodes) {
    ll res = 0;
    for (auto u : nodes[v].neigh)
        res += countFirst(u, nodes);
    ll got = nodes[nodes[v].head].st.Get(nodes[v].id, nodes[v].id);
    if (got > 0) {
        res += got;
        coverAll(nodes[v].leaf, got, nodes);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<node> nodes(n + 1);
        for (int i = 2; i <= n; i++) {
            cin >> nodes[i].p;
            nodes[nodes[i].p].neigh.push_back(i);
        }
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].a;
        Count(1, nodes);
        vector seq = {nodes[1].a};
        nodes[1].head = 1;
        nodes[1].id = 0;
        Traverse(1, nodes, seq);
        ll cur = countFirst(1, nodes);
        cout << cur << "\n";
        while (q--) {
            int u, x;
            cin >> u >> x;
            ll delt = x - nodes[u].a;
            nodes[u].a = x;
            nodes[nodes[u].head].st.Update(nodes[u].id, nodes[u].id, delt);
            u = nodes[u].leaf;
            ll mx = maxAll(u, nodes);
            coverAll(u, mx, nodes);
            cur += mx;
            cout << cur << "\n";
        }
    }
    return 0;
}
