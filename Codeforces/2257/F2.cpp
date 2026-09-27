#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

constexpr ll Inf = 4000000000000000000ll;

int X;

struct pos {
    ll sum{0};
    vector<llll> seq;
    vector<ll> tolast;
    pos(): seq(X), tolast(X) {}
};

llll Better(const llll& a, const llll& b) {
    if (a.first != b.first)
        return a.first < b.first? a : b;
    return a.second > b.second ? a : b;
}

llll getProt(const pos& p, ll ind) {
    if (ind < p.sum)
        return p.seq[ind];
    return {0, p.sum - 1};
}

pos Union(const pos& a, const pos& b) {
    pos c;
    c.sum = a.sum + b.sum;
    for (int i = 0; i < X; i++) {
        if (i < a.sum) {
            llll way1 = a.seq[i];
            llll way2 = {a.tolast[i], a.sum - 1};
            llll add1 = getProt(b, way1.second + X - a.sum);
            llll add2 = getProt(b, way2.second + X - a.sum);
            c.tolast[i] = min(way1.first + b.tolast[way1.second + X - a.sum],
                                way2.first + b.tolast[way2.second + X - a.sum]);
            way1.first += add1.first;
            way1.second = add1.second + a.sum;
            way2.first += add2.first;
            way2.second = add2.second + a.sum;
            c.seq[i] = Better(way1, way2);
        } else {
            c.seq[i] = getProt(b, i - a.sum);
            c.seq[i].second += a.sum;
            c.tolast[i] = b.tolast[i - a.sum];
        }
        if (i) {
            c.seq[i] = Better(c.seq[i], c.seq[i - 1]);
            c.tolast[i] = min(c.tolast[i], c.tolast[i - 1]);
        }
    }
    return c;
}

llll solveOne(ll nxt, int d, int s) {
    if (nxt >= d)
        return {0, d - 1};
    ll tims = (d - 1 - nxt) / X;
    nxt += tims * X;
    return {tims * s, nxt};
}

pos solveOne(int d, int s) {
    pos res;
    res.sum = d;
    for (int i = 0; i < X; i++) {
        res.seq[i] = solveOne(i, d, s);
        res.tolast[i] = res.seq[i].first;
        if (res.seq[i].second != d - 1)
            res.tolast[i] += s;
        if (i) {
            res.seq[i] = Better(res.seq[i], res.seq[i - 1]);
            res.tolast[i] = min(res.tolast[i], res.tolast[i - 1]);
        }
    }
    return res;
}

void Create(vector<pos>& st, int v, int l, int r, const vector<int>& d, const vector<int>& s) {
    if (l == r)
        st[v] = solveOne(d[l], s[l]);
    else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m, d, s);
        Create(st, 2 * v + 1, m + 1, r, d, s);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int x, const vector<int>& d, const vector<int>& s) {
    if (l == r)
        st[v] = solveOne(d[l], s[l]);
    else {
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, 2 * v, l, m, x, d, s);
        else Update(st, 2 * v + 1, m + 1, r, x, d, s);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

pos Solve(const vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v];
    int m = (l + r) / 2;
    if (b <= m)
        return Solve(st, 2 * v, l, m, a, b);
    if (m + 1 <= a)
        return Solve(st, 2 * v + 1, m + 1, r, a, b);
    return Union(Solve(st, 2 * v, l, m, a, m), Solve(st, 2 * v + 1, m + 1, r, m + 1, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, x;
    cin >> n >> q >> x;
    X = x;
    vector<pos> st(4 * (n + 1));
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    Create(st, 1, 1, n, d, s);
    while (q--) {
        char typ;
        cin >> typ;
        if (typ == '1') {
            int i, v;
            cin >> i >> v;
            d[i] = v;
            Update(st, 1, 1, n, i, d, s);
        } else if (typ == '2') {
            int i, y;
            cin >> i >> y;
            s[i] = y;
            Update(st, 1, 1, n, i, d, s);
        } else {
            int l, r;
            cin >> l >> r;
            cout << Solve(st, 1, 1, n, l, r).tolast[0] << "\n";
        }
    }
    return 0;
}
