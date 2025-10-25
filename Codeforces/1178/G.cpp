#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

struct ABCur {
    ll A, B, cur;
};

struct node {
    vector<int> neigh;
    ll A, B;
    int lef, rig;
};

void Traverse(vector<node>& tree, int v, vector<ABCur>& lines) {
    static int cur = -1;
    tree[v].lef = ++cur;
    lines.emplace_back(tree[v].A, abs(tree[v].B), 0ll);
    for (auto& u : tree[v].neigh) {
        tree[u].A += tree[v].A;
        tree[u].B += tree[v].B;
        Traverse(tree, u, lines);
    }
    tree[v].rig = cur;
}

void Update(vector<ABCur>& lines, vector<HullDynamic>& hd, vector<ll>& add,
    int lef, int rig, int x) {
    int p = hd.size();
    while (lef <= rig && lef % p != 0) {
        lines[lef].A += x;
        lines[lef].cur += lines[lef].B * x;
        hd[lef / p].insert_line(lines[lef].B, lines[lef].cur);
        lef++;
    }
    while (lef <= rig && rig % p != p - 1) {
        lines[rig].A += x;
        lines[rig].cur += lines[rig].B * x;
        hd[rig / p].insert_line(lines[rig].B, lines[rig].cur);
        rig--;
    }
    if (lef > rig)
        return;
    int to = rig / p;
    for (int i = lef / p; i <= to; i++)
        add[i] += x;
}

ll getMax(const vector<ABCur>& lines, vector<HullDynamic>& hd, const vector<ll>& add,
    int lef, int rig) {
    ll res = 0;
    int p = hd.size();
    while (lef <= rig && lef % p != 0) {
        res = max(res, lines[lef].cur + lines[lef].B * add[lef / p]);
        lef++;
    }
    while (lef <= rig && rig % p != p - 1) {
        res = max(res, lines[rig].cur + lines[rig].B * add[rig / p]);
        rig--;
    }
    if (lef > rig)
        return res;
    int to = rig / p;
    for (int i = lef / p; i <= to; i++)
        res = max(res, hd[i].eval(add[i]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<node> tree(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        tree[p].neigh.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> tree[i].A;
    for (int i = 1; i <= n; i++)
        cin >> tree[i].B;
    vector<ABCur> lines;
    Traverse(tree, 1, lines);
    int p = sqrt(n + 1) + 2;
    vector<HullDynamic> hd(p);
    vector add(p, 0ll);
    for (int i = 0; i < lines.size(); i++) {
        lines[i].cur = lines[i].A * lines[i].B;
        hd[i / p].insert_line(lines[i].B, lines[i].cur);
    }
    vector<vector<int>> queries(q);
    vector<ll> res(q, 0);
    for (int i = 0; i < q; i++) {
        auto& V = queries[i];
        int typ, v;
        cin >> typ >> v;
        if (typ == 1) {
            int x;
            cin >> x;
            V = {v, x};
            Update(lines, hd, add, tree[v].lef, tree[v].rig, x);
        } else {
            V = {v};
            res[i] = max(res[i], getMax(lines, hd, add, tree[v].lef, tree[v].rig));
        }
    }
    for (int i = 0; i < lines.size(); i++) {
        lines[i].A += add[i / p];
        lines[i].cur = -lines[i].A * lines[i].B;
    }
    for (int i = 0; i < p; i++) {
        hd[i].clear();
        add[i] = 0;
    }
    for (int i = 0; i < lines.size(); i++)
        hd[i / p].insert_line(lines[i].B, lines[i].cur);
    for (int i = q - 1; i >= 0; i--) {
        int v = queries[i][0];
        if (queries[i].size() > 1) {
            int x = queries[i][1];
            Update(lines, hd, add, tree[v].lef, tree[v].rig, x);
        } else res[i] = max(res[i], getMax(lines, hd, add, tree[v].lef, tree[v].rig));
    }
    for (int i = 0; i < q; i++)
        if (queries[i].size() == 1)
            cout << res[i] << "\n";
    return 0;
}
