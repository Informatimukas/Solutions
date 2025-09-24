#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

struct pos {
    ll value;
    ll flag{0};
};

void downOn(pos& v, ll fl) {
    v.value += fl;
    v.flag += fl;
}

void Down(vector<pos>& st, int v) {
    if (st[v].flag) {
        downOn(st[2 * v], st[v].flag);
        downOn(st[2 * v + 1], st[v].flag);
        st[v].flag = 0;
    }
}

void Create(vector<pos>& st, int v, int l, int r) {
    if (l == r)
        st[v].value = l == 0 ? 0 : -Inf;
    else {
        int m = l + r >> 1;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
        st[v].value = max(st[2 * v].value, st[2 * v + 1].value);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int x, ll val) {
    if (l == r) {
        st[v].value = max(st[v].value, val);
        return;
    }
    Down(st, v);
    int m = l + r >> 1;
    if (x <= m) Update(st, 2 * v, l, m, x, val);
    else Update(st, 2 * v + 1, m + 1, r, x, val);
    st[v].value = max(st[2 * v].value, st[2 * v + 1].value);
}

void Add(vector<pos>& st, int v, int l, int r, int a, int b, ll val) {
    if (l == a && r == b) {
        downOn(st[v], val);
        return;
    }
    Down(st, v);
    int m = l + r >> 1;
    if (a <= m)
        Add(st, 2 * v, l, m, a, min(m, b), val);
    if (m + 1 <= b)
        Add(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, val);
    st[v].value = max(st[2 * v].value, st[2 * v + 1].value);
}

ll getMax(vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v].value;
    Down(st, v);
    ll res = -Inf;
    int m = l + r >> 1;
    if (a <= m)
        res = max(res, getMax(st, 2 * v, l, m, a, min(m, b)));
    if (m + 1 <= b)
        res = max(res, getMax(st, 2 * v + 1, m + 1, r, max(m + 1, a), b));
    return res;
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
        vector<int> v(n);
        for (auto& x : v)
            cin >> x;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
            x--;
        }
        vector<int> inb(n);
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            b--;
            inb[b] = i;
        }
        vector<pos> st(4 * (n + 1));
        Create(st, 1, 0, n);
        for (auto& item : a) {
            int y = inb[item];
            ll best = getMax(st, 1, 0, n, 0, y);
            Add(st, 1, 0, n, 0, y, v[item]);
            Update(st, 1, 0, n, y + 1, best);
        }
        cout << getMax(st, 1, 0, n, 0, n) << "\n";
    }
    return 0;
}
