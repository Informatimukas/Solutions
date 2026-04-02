#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    ll min_even, max_even;
    ll min_odd, max_odd;
};

pos Union(const pos& a, const pos& b) {
    pos c;
    c.min_even = min(a.min_even + b.min_even, a.min_odd - b.max_odd);
    c.max_even = max(a.max_even + b.max_even, a.max_odd - b.min_odd);
    c.min_odd = min(a.min_even + b.min_odd, a.min_odd - b.max_even);
    c.max_odd = max(a.max_even + b.max_odd, a.max_odd - b.min_even);
    return c;
}

void Create(vector<pos>& st, int v, int l, int r, const vector<int>& a) {
    if (l == r) {
        st[v].min_odd = st[v].max_odd = -a[l];
        st[v].min_even = st[v].max_even = 0;
    } else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m, a);
        Create(st, 2 * v + 1, m + 1, r, a);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

pos Get(const vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v];
    int m = (l + r) / 2;
    if (b <= m)
        return Get(st, 2 * v, l, m, a, b);
    if (m + 1 <= a)
        return Get(st, 2 * v + 1, m + 1, r, a, b);
    return Union(Get(st, 2 * v, l, m, a, m),
                Get(st, 2 * v + 1, m + 1, r, m + 1, b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pos> st(4 * n);
    Create(st, 1, 1, n, a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto got = Get(st, 1, 1, n, l, r);
        cout << max(got.max_even, got.max_odd) << "\n";
    }
    return 0;
}
