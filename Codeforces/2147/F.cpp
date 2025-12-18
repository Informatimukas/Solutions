#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getCost(ll cnt) { return cnt * (cnt + 1) / 2; }

struct rang {
    int cnt{0}, lef{0}, rig{0};
    ll cost{0};
};

struct pos {
    rang joined;
    int filled{0};
};

rang getRang(const pos& p) {
    return p.filled > 0 ? rang{p.joined.cnt, p.joined.cnt, p.joined.cnt,
        getCost(p.joined.cnt)} : p.joined;
}

rang Union(const pos& p1, const pos& p2) {
    rang r1 = getRang(p1), r2 = getRang(p2);
    rang nw;
    nw.cnt = r1.cnt + r2.cnt;
    nw.lef = r1.lef == r1.cnt ? r1.lef + r2.lef : r1.lef;
    nw.rig = r2.rig == r2.cnt ? r2.rig + r1.rig : r2.rig;
    nw.cost = r1.cost + r2.cost - getCost(r1.rig) - getCost(r2.lef) +
        getCost(r1.rig + r2.lef);
    return nw;
}

void downOn(pos& p, int f) {
    p.filled += f;
}

void Create(vector<pos>& st, int v, int l, int r) {
    st[v].joined.cnt = r - l + 1;
    if (l < r) {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, int val) {
    if (l == a && r == b)
        downOn(st[v], val);
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        st[v].joined = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(vector<pos>& st, int n, int a, int b, int val) {
    int lef = min(a, b), rig = max(a, b) - 1;
    if (lef <= rig)
        Update(st, 1, 1, n, lef, rig, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<pos> st(4 * n);
        Create(st, 1, 1, n);
        array<vector<int>, 2> P;
        for (auto& V : P) {
            V.resize(n + 1);
            for (int i = 1; i <= n; i++)
                cin >> V[i];
        }
        for (int i = 1; i <= n; i++)
            Update(st, n, P[0][i], P[1][i], 1);
        while (q--) {
            int typ, i, j;
            cin >> typ >> i >> j;
            --typ;
            Update(st, n, P[0][i], P[1][i], -1);
            Update(st, n, P[0][j], P[1][j], -1);
            swap(P[typ][i], P[typ][j]);
            Update(st, n, P[0][i], P[1][i], 1);
            Update(st, n, P[0][j], P[1][j], 1);
            auto r = getRang(st[1]);
            cout << r.cost + getCost(n) << "\n";
        }
    }
    return 0;
}