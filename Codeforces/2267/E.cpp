#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    array<ll, 2> L{}, R{};
    ll res{};
};

node Union(const node& a, const node& b) {
    node c;
    c.L[0] = a.L[0] + a.L[0] * b.L[0] + a.L[1] * b.L[1];
    c.L[1] = a.L[1] + a.L[0] * b.L[1] + a.L[1] * b.L[0];
    c.R[0] = b.R[0] + b.R[0] * a.R[0] + b.R[1] * a.R[1];
    c.R[1] = b.R[1] + b.R[0] * a.R[1] + b.R[1] * a.R[0];
    c.res = a.res + b.res + a.R[0] * b.L[1] + a.R[1] * b.L[0];
    return c;
}

void Create(vector<node>& st, int v, int l, int r, const vector<int>& a) {
    if (l == r) {
        st[v].L[a[l]] = st[v].R[a[l]] = 1;
        st[v].L[!a[l]] = st[v].R[!a[l]] = 0;
        st[v].res = st[v].L[1];
        return;
    }
    int m = (l + r) / 2;
    Create(st, 2 * v, l, m, a);
    Create(st, 2 * v + 1, m + 1, r, a);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

void Update(vector<node>& st, int v, int l, int r, int x, const vector<int>& a) {
    if (l == r) {
        st[v].L[a[l]] = st[v].R[a[l]] = 1;
        st[v].L[!a[l]] = st[v].R[!a[l]] = 0;
        st[v].res = st[v].L[1];
        return;
    }
    int m = (l + r) / 2;
    if (x <= m)
        Update(st, 2 * v, l, m, x, a);
    else Update(st, 2 * v + 1, m + 1, r, x, a);
    st[v] = Union(st[2 * v], st[2 * v + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 1; i < n; i++)
            a[i] = s[i] != s[i - 1];
        vector<node> st(4 * n);
        Create(st, 1, 1, n - 1, a);
        cout << "create" << endl;
        cout << st[1].res;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (x < n) {
                a[x] = !a[x];
                Update(st, 1, 1, n - 1, x, a);
            }
            if (x > 1) {
                a[x - 1] = !a[x - 1];
                Update(st, 1, 1, n - 1, x - 1, a);
            }
            cout << " " << st[1].res;
        }
        cout << "\n";
    }
    return 0;
}
