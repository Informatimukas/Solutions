#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Inf = 1000000007;

struct node {
    ll cnt{0}, sum{0};
};

node Union(const node& a, const node& b) {
    return {a.cnt + b.cnt, a.sum + b.sum};
}

void Create(vector<node>& st, int v, int l, int r, const vector<int>& a) {
    if (l == r) {
        st[v].cnt = a[l];
        st[v].sum = a[l] * static_cast<ll>(l);
        return;
    }
    int m = (l + r) / 2;
    Create(st, 2 * v, l, m, a);
    Create(st, 2 * v + 1, m + 1, r, a);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

node Get(const vector<node>& st, int v, int l, int r, int x) {
    if (r <= x)
        return st[v];
    int m = (l + r) / 2;
    if (x <= m)
        return Get(st, 2 * v, l, m, x);
    return Union(st[2 * v], Get(st, 2 * v + 1, m + 1, r, x));
}

ll Solve(const vector<node>& st, int v, int l, int r, ll x) {
    if (l == r)
        return l * x;
    int m = (l + r) / 2;
    if (x <= st[2 * v].cnt)
        return Solve(st, 2 * v, l, m, x);
    return st[2 * v].sum + Solve(st, 2 * v + 1, m + 1, r, x - st[2 * v].cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> seq(n);
        for (int i = 0; i + 1 < n; i++)
            seq[i] = k - (a[i + 1] - a[i]);
        seq[n - 1] = Inf;
        vector<node> st(4 * n);
        Create(st, 1, 0, n - 1, seq);
        for (int i = 0; i < n; i++) {
            ll res = 0;
            if (0 < i && i < n - 1) {
                node got = Get(st, 1, 0, n - 1, i);
                int nd = a[i + 1] - a[i - 1] - k;
                if (nd > 0)
                    res = Solve(st, 1, 0, n - 1, got.cnt + nd) - got.sum - i * static_cast<ll>(nd);
            }
            cout << res << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
