#include <bits/stdc++.h>
using namespace std;

struct node {
    int a{0};
    vector<int> neigh;
    int lef{0}, rig{0};
};

struct rang {
    optional<int> lef, rig;
    int good{0};
};

struct pos {
    array<rang, 2> arr{};
    bool flag{false};
};

void Traverse(vector<node>& nodes, vector<int>& vals, vector<int>& rig, int v, int p) {
    static int cur = 0;
    nodes[v].lef = ++cur;
    vals[nodes[v].lef] = nodes[v].a;
    for (auto& u : nodes[v].neigh) {
        if (u == p)
            continue;
        Traverse(nodes, vals, rig, u, v);
    }
    nodes[v].rig = rig[nodes[v].lef] = cur;
}

rang Union(const rang& a, const rang& b, const vector<int>& rig) {
    rang c;
    c.lef = a.lef ? a.lef : b.lef;
    c.rig = b.rig ? b.rig : a.rig;
    c.good = a.good + b.good;
    if (a.rig && b.lef && *b.lef <= rig[*a.rig])
        --c.good;
    return c;
}

pos Union(const pos& a, const pos& b, const vector<int>& rig) {
    return {{Union(a.arr[0], b.arr[0], rig), Union(a.arr[1], b.arr[1], rig)}};
}

void downOn(pos& p) {
    swap(p.arr[0], p.arr[1]);
    p.flag ^= true;
}

void Down(vector<pos>& st, int v) {
    if (st[v].flag) {
        downOn(st[2 * v]);
        downOn(st[2 * v + 1]);
        st[v].flag = false;
    }
}

void Create(vector<pos>& st, int v, int l, int r,
    const vector<int>& vals, const vector<int>& rig) {
    if (l == r) {
        st[v].arr[vals[l]] = {l, l, 1};
        st[v].arr[1 - vals[l]] = {{}, {}, 0};
    } else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m, vals, rig);
        Create(st, 2 * v + 1, m + 1, r, vals, rig);
        st[v] = Union(st[2 * v], st[2 * v + 1], rig);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b,
    const vector<int>& rig) {
    if (l == a && r == b)
        downOn(st[v]);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), rig);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, rig);
        st[v] = Union(st[2 * v], st[2 * v + 1], rig);
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
        vector<node> nodes(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].a;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        vector<int> vals(n + 1), rig(n + 1);
        cout << "setup" << endl;
        Traverse(nodes, vals, rig, 1, 0);
        cout << "traverse" << endl;
        vector<pos> st(4 * n);
        Create(st, 1, 1, n, vals, rig);
        cout << "Create" << endl;
        cout << st[1].arr[0].good << "\n";
        int q;
        cin >> q;
        while (q--) {
            int v;
            cin >> v;
            Update(st, 1, 1, n, nodes[v].lef, nodes[v].rig, rig);
            cout << st[1].arr[0].good << "\n";
        }
    }
    return 0;
}
