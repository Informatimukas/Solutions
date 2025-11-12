#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Maxb = 20;

struct node {
    vector<ii> neigh;
    int lef, rig;
    int mylvl;
};

struct pos {
    int flag{0};
    array<array<int, 2>, Maxb> cnt;
};

struct pos2 {
    array<pos, 2> pos{};
};

void Traverse(vector<node>& nodes, int v, int p, int w, int lvl, vector<int>& seq,
    vector<int>& levels) {
    nodes[v].lef = seq.size();
    seq.push_back(w);
    levels.push_back(lvl);
    nodes[v].mylvl = lvl;
    for (auto& [u, weight] : nodes[v].neigh) {
        if (u == p)
            continue;
        Traverse(nodes, u, v, w ^ weight, (lvl + 1) % 2, seq, levels);
    }
    nodes[v].rig = seq.size() - 1;
}

array<array<int, 2>, Maxb> Union(const array<array<int, 2>, Maxb>& a,
    const array<array<int, 2>, Maxb>& b) {
    array<array<int, 2>, Maxb> res;
    for (int i = 0; i < Maxb; i++)
        for (int j = 0; j < 2; j++)
            res[i][j] = a[i][j] + b[i][j];
    return res;
}

pos2 Union(const pos2& a, const pos2& b) {
    pos2 res;
    for (int i = 0; i < 2; i++)
        res.pos[i].cnt = Union(a.pos[i].cnt, b.pos[i].cnt);
    return res;
}

void downOn(pos& p, int fl) {
    p.flag ^= fl;
    for (int i = 0; i < Maxb; i++)
        if (fl & 1 << i)
            swap(p.cnt[i][0], p.cnt[i][1]);
}

void Down(vector<pos2>& st, int v) {
    for (int i = 0; i < 2; i++)
        if (st[v].pos[i].flag) {
            downOn(st[2 * v].pos[i], st[v].pos[i].flag);
            downOn(st[2 * v + 1].pos[i], st[v].pos[i].flag);
            st[v].pos[i].flag = 0;
        }
}

void Create(vector<pos2>& st, int v, int l, int r, const vector<int>& seq,
    const vector<int>& levels) {
    if (l == r) {
        for (int lvl = 0; lvl < 2; lvl++)
            if (lvl != levels[l])
                for (int i = 0; i < Maxb; i++)
                    st[v].pos[lvl].cnt[i] = {0, 0};
            else
                for (int i = 0; i < Maxb; i++)
                    if (seq[l] & 1 << i)
                        st[v].pos[lvl].cnt[i] = {0, 1};
                    else st[v].pos[lvl].cnt[i] = {1, 0};
        return;
    }
    int m = (l + r) / 2;
    Create(st, 2 * v, l, m, seq, levels);
    Create(st, 2 * v + 1, m + 1, r, seq, levels);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

void Update(vector<pos2>& st, int v, int l, int r, int a, int b, int lvl, int val) {
    if (l == a && r == b) {
        downOn(st[v].pos[lvl], val);
        return;
    }
    Down(st, v);
    int m = (l + r) / 2;
    if (a <= m)
        Update(st, 2 * v, l, m, a, min(m, b), lvl, val);
    if (m + 1 <= b)
        Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, lvl, val);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

pos2 Get(vector<pos2>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v];
    Down(st, v);
    int m = (l + r) / 2;
    if (b <= m)
        return Get(st, 2 * v, l, m, a, b);
    if (m + 1 <= a)
        return Get(st, 2 * v + 1, m + 1, r, a, b);
    return Union(Get(st, 2 * v, l, m, a, m),
        Get(st, 2 * v + 1, m + 1, r, m + 1, b));
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
        for (int i = 0; i < n - 1; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            nodes[a].neigh.emplace_back(b, w);
            nodes[b].neigh.emplace_back(a, w);
        }
        vector<int> seq, levels;
        Traverse(nodes, 1, 0, 0, 0, seq, levels);
        vector<pos2> st(4 * n);
        Create(st, 1, 0, n - 1, seq, levels);
        int q;
        cin >> q;
        while (q--) {
            int typ;
            cin >> typ;
            if (typ == 2) {
                int v;
                cin >> v;
                auto got = Get(st, 1, 0, n - 1, nodes[v].lef, nodes[v].rig);
                ll res = 0;
                for (int i = 0; i < Maxb; i++) {
                    int zers = got.pos[0].cnt[i][0] + got.pos[1].cnt[i][0];
                    int ones = got.pos[0].cnt[i][1] + got.pos[1].cnt[i][1];
                    res += static_cast<ll>(1 << i) * zers * ones;
                }
                cout << res << "\n";
            } else {
                int v, w;
                cin >> v >> w;
                Update(st, 1, 0, n - 1, nodes[v].lef, nodes[v].rig, 1 - nodes[v].mylvl, w);
            }
        }
    }
    return 0;
}