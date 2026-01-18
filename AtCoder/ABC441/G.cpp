#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

struct miniFlag {
    bool er{false};
    ll add{0};
    bool Empty() {
        return !er && !add;
    }
    void Clear() { er = false; add = 0; }
};

miniFlag Add(miniFlag cur, const miniFlag& nw) {
    if (nw.er) {
        cur.er = true;
        cur.add = 0;
    }
    cur.add += nw.add;
    return cur;
}

struct flag {
    bool swap{false};
    array<miniFlag, 2> a{};
    bool Empty() {
        return !swap && a[0].Empty() && a[1].Empty();
    }
    void Clear() {
        swap = false;
        a[0].Clear();
        a[1].Clear();
    }
};

struct node {
    array<ll, 2> best{0ll, -Inf};
    flag fl;
};

void downOn(node& nod, const flag& f) {
    if (f.swap) {
        nod.fl.swap ^= true;
        swap(nod.best[0], nod.best[1]);
        swap(nod.fl.a[0], nod.fl.a[1]);
    }
    for (int i = 0; i < 2; i++) {
        nod.fl.a[i] = Add(nod.fl.a[i], f.a[i]);
        if (f.a[i].er)
            nod.best[i] = min(nod.best[i], 0ll);
        nod.best[i] += f.a[i].add;
    }
}

void Down(vector<node>& st, int v) {
    if (!st[v].fl.Empty()) {
        downOn(st[2 * v], st[v].fl);
        downOn(st[2 * v + 1], st[v].fl);
        st[v].fl.Clear();
    }
}

void Union(node& c, const node& a, const node& b) {
    for (int i = 0; i < c.best.size(); i++)
        c.best[i] = max(a.best[i], b.best[i]);
}

void Update(vector<node>& st, int v, int l, int r, int a, int b, const flag& f) {
    if (l == a && r == b)
        downOn(st[v], f);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), f);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, f);
        Union(st[v], st[2 * v], st[2 * v + 1]);
    }
}

ll getBest(vector<node>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return max(0ll, st[v].best[0]);
    Down(st, v);
    int m = (l + r) / 2;
    ll res = 0;
    if (a <= m)
        res = max(res, getBest(st, 2 * v, l, m, a, min(m, b)));
    if (m + 1 <= b)
        res = max(res, getBest(st, 2 * v + 1, m + 1, r, max(m + 1, a), b));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<node> st(4 * n);
    while (q--) {
        int typ, l, r;
        cin >> typ >> l >> r;
        if (typ == 1) {
            ll x;
            cin >> x;
            flag fl;
            fl.a[0].add = x;
            Update(st, 1, 1, n, l, r, fl);
        } else if (typ == 2) {
            flag fl;
            fl.swap = true;
            fl.a[1].er = true;
            Update(st, 1, 1, n, l, r, fl);
        } else cout << getBest(st, 1, 1, n, l, r) << "\n";
    }
    return 0;
}
