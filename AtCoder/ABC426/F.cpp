#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;
using llii = pair<lli, int>;

constexpr ll Inf = 1000000000000000000ll;

struct pos {
    lli mn;
    ll flag{0};
    int cnt;
    pos() = default;
    pos(ll a, int ind) {
        if (a == 0) {
            mn = {Inf, -1};
            cnt = 0;
        } else {
            mn = {a, ind};
            cnt = 1;
        }
    }
};

void downOn(vector<pos>& st, int v, ll val) {
    st[v].mn.first -= val;
    st[v].flag += val;
}

void Down(vector<pos>& st, int v) {
    if (st[v].flag) {
        downOn(st, 2 * v, st[v].flag);
        downOn(st, 2 * v + 1, st[v].flag);
        st[v].flag = 0;
    }
}

pos Union(const pos& a, const pos& b) {
    pos res;
    res.mn = min(a.mn, b.mn);
    res.cnt = a.cnt + b.cnt;
    return res;
}

void Create(vector<pos>& st, int v, int l, int r, const vector<ll>& a) {
    if (l == r)
        st[v] = pos(a[l], l);
    else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m, a);
        Create(st, 2 * v + 1, m + 1, r, a);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

llii operator+(const llii& a, const llii& b) {
    return {min(a.first, b.first), a.second + b.second};
}

llii Get(vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return {st[v].mn, st[v].cnt};
    Down(st, v);
    int m = (l + r) / 2;
    llii res = {{Inf, -1}, 0};
    if (a <= m)
        res = res + Get(st, 2 * v, l, m, a, min(m, b));
    if (m + 1 <= b)
        res = res + Get(st, 2 * v + 1, m + 1, r, max(m + 1, a), b);
    return res;
}

void Remove(vector<pos>& st, int v, int l, int r, int x) {
    if (l == r)
        st[v] = pos(0, l);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (x <= m)
            Remove(st, 2 * v, l, m, x);
        else Remove(st, 2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, ll val) {
    if (l == a && r == b)
        downOn(st, v, val);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pos> st(4 * n);
    Create(st, 1, 1, n, a);
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        ll res = 0;
        llii got;
        while (true) {
            got = Get(st, 1, 1, n, l, r);
            if (got.first.first <= k) {
                res += got.first.first;
                Remove(st, 1, 1, n, got.first.second);
                continue;
            }
            res += static_cast<ll>(k) * got.second;
            Update(st, 1, 1, n, l, r, k);
            break;
        }
        cout << res << "\n";
    }
    return 0;
}
