#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;
constexpr int inv2 = (mod + 1) / 2;

struct segtree {
    vector<int> seq;
    vector<int> st, fl;
    void downOn(int v, int f) {
        st[v] = static_cast<ll>(st[v]) * f % mod;
        fl[v] = static_cast<ll>(fl[v]) * f % mod;
    }
    void Down(int v) {
        if (fl[v]) {
            downOn(2 * v, fl[v]);
            downOn(2 * v + 1, fl[v]);
            fl[v] = 1;
        }
    }
    void Union(int v) {
        st[v] = (st[2 * v] + st[2 * v + 1]) % mod;
    }
    void Create(int v, int l, int r) {
        fl[v] = 1;
        if (l == r)
            st[v] = l == 0? 1 : 0;
        else {
            int m = l + r >> 1;
            Create(2 * v, l, m);
            Create(2 * v + 1, m + 1, r);
            Union(v);
        }
    }
    void Create(const vector<int>& gseq) {
        seq = gseq;
        st.resize(gseq.size() * 4);
        fl.resize(gseq.size() * 4);
        Create(1, 0, seq.size() - 1);
    }
    void Update(int v, int l, int r, int a, int b, int val) {
        if (l == a && r == b)
            downOn(v, val);
        else {
            Down(v);
            int m = l + r >> 1;
            if (a <= m)
                Update(2 * v, l, m, a, min(m, b), val);
            if (m + 1 <= b)
                Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
            Union(v);
        }
    }
    int Get(int v, int l, int r, int x) {
        if (l == r) return st[v];
        Down(v);
        int m = l + r >> 1;
        if (x <= m)
            return Get(2 * v, l, m, x);
        return Get(2 * v + 1, m + 1, r, x);
    }
    void Add(int v, int l, int r, int x, int val) {
        if (l == r)
            st[v] = (st[v] + val) % mod;
        else {
            Down(v);
            int m = l + r >> 1;
            if (x <= m)
                Add(2 * v, l, m, x, val);
            else Add(2 * v + 1, m + 1, r, x, val);
            Union(v);
        }
    }
    int Process(int x) {
        auto ind = distance(seq.begin(), ranges::lower_bound(seq, x));
        Update(1, 0, seq.size() - 1, ind, seq.size() - 1, 2);
        if (seq[ind] != x)
            return 0;
        int res = Get(1, 0, seq.size() - 1, ind - 1);
        Add(1, 0, seq.size() - 1, ind, res);
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> L = {0}, R = {0};
        for (auto& x : a) {
            cin >> x;
            if (L.empty() || L.back() < x)
                L.push_back(x);
        }
        int mx = L.back();
        segtree Ltree;
        Ltree.Create(L);
        vector res1(n, 0);
        for (int i = 0; i < n; i++) {
            int cur = Ltree.Process(a[i]);
            if (a[i] == mx)
                res1[i] = cur;
        }
        for (int i = n - 1; i >= 0; i--)
            if (R.empty() || R.back() < a[i])
                R.push_back(a[i]);
        segtree Rtree;
        Rtree.Create(R);
        vector res2(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int cur = Rtree.Process(a[i]);
            if (a[i] == mx)
                res2[i] = cur;
        }
        vector<int> pw2(n + 1), ipw2(n + 1);
        pw2[0] = ipw2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw2[i] = 2ll * pw2[i - 1] % mod;
            ipw2[i] = static_cast<ll>(inv2) * ipw2[i - 1] % mod;
        }
        int res = 0, lef = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == mx) {
                res = (res + static_cast<ll>(res1[i]) * res2[i]) % mod;
                res = (res + static_cast<ll>(lef) * res2[i] % mod * pw2[i]) % mod;
                lef = (lef + static_cast<ll>(res1[i]) * ipw2[i + 1]) % mod;
            }
        cout << res << "\n";
    }
    return 0;
}
