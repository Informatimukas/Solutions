#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    int mx{0}, siz{0};
    int lef{0}, rig{0};
    ll ways{0};
};

pos Merge(const pos& a, const pos& b) {
    pos res;
    res.mx = max(a.mx, b.mx);
    res.siz = a.siz + b.siz;
    if (res.mx == a.mx) {
        res.ways += a.ways;
        if (a.lef == a.siz && res.mx == b.mx)
            res.lef = a.lef + b.lef;
        else res.lef = a.lef;
    } else res.lef = 0;
    if (res.mx == b.mx) {
        res.ways += b.ways;
        if (b.rig == b.siz && res.mx == a.mx)
            res.rig = b.rig + a.rig;
        else res.rig = b.rig;
    } else res.rig = 0;
    if (res.mx == a.mx && res.mx == b.mx)
        res.ways += static_cast<ll>(a.rig) * b.lef;
    return res;
}

void Create(vector<pos>& st, int v, int l, int r) {
    if (l == r) {
        st[v].mx = 0;
        st[v].siz = st[v].lef = st[v].rig = 1;
        st[v].ways = 1;
    } else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
        st[v] = Merge(st[2 * v], st[2 * v + 1]);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int x, int val) {
    if (l == r)
        st[v].mx = val;
    else {
        int m = (l + r) / 2;
        if (x <= m)
            Update(st, 2 * v, l, m, x, val);
        else Update(st, 2 * v + 1, m + 1, r, x, val);
        st[v] = Merge(st[2 * v], st[2 * v + 1]);
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
        vector<int> a(n + 1);
        vector<set<int>> S(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            S[a[i]].insert(i);
        }
        vector<pos> st(4 * n);
        Create(st, 1, 1, n);
        for (int i = 1; i <= n; i++)
            if (!S[i].empty())
                Update(st, 1, 1, n, *S[i].begin(), *S[i].rbegin() - *S[i].begin());
        while (q--) {
            int ind, x;
            cin >> ind >> x;
            Update(st, 1, 1, n, *S[a[ind]].begin(), 0);
            S[a[ind]].erase(ind);
            if (!S[a[ind]].empty())
                Update(st, 1, 1, n, *S[a[ind]].begin(),
                    *S[a[ind]].rbegin() - *S[a[ind]].begin());
            a[ind] = x;
            if (!S[a[ind]].empty())
                Update(st, 1, 1, n, *S[a[ind]].begin(), 0);
            S[a[ind]].insert(ind);
            Update(st, 1, 1, n, *S[a[ind]].begin(),
                *S[a[ind]].rbegin() - *S[a[ind]].begin());
            int r1 = st[1].mx;
            ll r2 = st[1].ways;
            if (r1 == 0)
                r2 = 0;
            cout << r1 << " " << r2 << "\n";
        }
    }
    return 0;
}
