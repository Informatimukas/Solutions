#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 2000000000;

struct node {
    int mn, mx;
    int res;
};

node Union(const node& lef, const node& rig, int L, int R) {
    node res;
    res.mn = min(lef.mn, rig.mn);
    res.mx = max(lef.mx, rig.mx);
    if (lef.mx <= rig.mn)
        res.res = max(lef.res, rig.res);
    else res.res = (R - L + 1) / 2;
    return res;
}

void Create(vector<node>& st, const vector<int>& a, int v, int l, int r) {
    if (l >= a.size()) {
        st[v].mn = st[v].mx = Inf;
        st[v].res = 0;
        return;
    }
    if (l == r) {
        st[v].mn = st[v].mx = a[l];
        st[v].res = 0;
    } else {
        int m = (l + r) / 2;
        Create(st, a, 2 * v, l, m);
        Create(st, a, 2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1], l, r);
    }
}

void Update(vector<node>& st, const vector<int>& a, int v, int l, int r, int x) {
    if (l == r) {
        st[v].mn = st[v].mx = a[l];
        st[v].res = 0;
    } else {
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, a, 2 * v, l, m, x);
        else Update(st, a, 2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1], l, r);
    }
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int pw = 1;
        while (pw < n)
            pw *= 2;
        vector<node> st(4 * pw);
        Create(st, a, 1, 0, pw - 1);
        cout << st[1].res << "\n";
        while (q--) {
            int ind, x;
            cin >> ind >> x;
            a[ind] = x;
            Update(st, a, 1, 0, pw - 1, ind);
            cout << st[1].res << "\n";
        }
    }
    return 0;
}
