#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 300005;
constexpr int Inf = 1000000000;

struct pos {
    int mn[2], mx[2];
    int best, flag;
};

struct segtree {
    vector<pos> st;
    vector<int> un;
    int n;
    void Union(int v) {
        int lc = 2 * v, rc = 2 * v + 1;
        st[v].best = max(st[lc].best, st[rc].best);
        for (int i = 0; i < 2; i++) {
            st[v].mn[i] = min(st[lc].mn[i], st[rc].mn[i]);
            st[v].mx[i] = max(st[lc].mx[i], st[rc].mx[i]);
            for (int j = 0; j < 2; j++)
                st[v].best = max(st[v].best,
                    st[rc].mx[i] - st[lc].mn[j] - static_cast<int>(i == 1 && j == 0));
        }
    }
    void downOn(int v, int f) {
        for (int i = 0; i < 2; i++) {
            st[v].mn[i] += f;
            st[v].mx[i] += f;
        }
        st[v].flag += f;
    }
    void Down(int v) {
        if (st[v].flag) {
            downOn(2 * v, st[v].flag);
            downOn(2 * v + 1, st[v].flag);
            st[v].flag = 0;
        }
    }
    void Add(int v, int l, int r, int a, int b, int x) {
        if (l == a && r == b) downOn(v, x);
        else {
            Down(v);
            int m = l + r >> 1;
            if (a <= m) Add(2 * v, l, m, a, min(m, b), x);
            if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
            Union(v);
        }
    }
    void Create(int v, int l, int r) {
        st[v].mn[0] = st[v].mn[1] = Inf;
        st[v].mx[0] = st[v].mx[1] = -Inf;
        st[v].best = st[v].flag = 0;
        if (l == r) {
            int wh = un[l] % 2;
            st[v].mn[wh] = st[v].mx[wh] = -(un[l] / 2);
        } else {
            int m = l + r >> 1;
            Create(2 * v, l, m);
            Create(2 * v + 1, m + 1, r);
            Union(v);
        }
    }
    segtree() {}
    segtree(const vector<int> &gun) {
        un = gun;
        n = un.size();
        int m = 1;
        while (m < n) m <<= 1;
        m <<= 1;
        st.resize(m);
        Create(1, 0, n - 1);
    }
    void Add(int rind, int delt) {
        auto it = lower_bound(un.begin(), un.end(), rind);
        int l = it - un.begin();
        Add(1, 0, n - 1, l, n - 1, delt);
    }
    int Get() { return st[1].best; }
} st[Maxn];

int T;
int n, q;
int a[Maxn];
vector<int> un[Maxn];
int qi[Maxn], qx[Maxn];
multiset<int> S;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++)
            un[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            un[a[i]].push_back(i);
            un[a[i]].push_back(i - 1);
        }
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &qi[i], &qx[i]);
            un[qx[i]].push_back(qi[i]);
            un[qx[i]].push_back(qi[i] - 1);
        }
        S.clear();
        for (int i = 1; i <= n; i++) {
            ranges::sort(un[i]);
            un[i].erase(ranges::unique(un[i]).begin(), un[i].end());
            if (!un[i].empty()) st[i] = segtree(un[i]);
        }
        for (int i = 1; i <= n; i++)
            st[a[i]].Add(i, 1);
        for (int i = 1; i <= n; i++) if (!un[i].empty())
            S.insert(st[i].Get());
        for (int i = 1; i <= q; i++) {
            int old = a[qi[i]], nw = qx[i];
            S.erase(S.find(st[old].Get()));
            st[old].Add(qi[i], -1);
            S.insert(st[old].Get());
            a[qi[i]] = nw;
            S.erase(S.find(st[nw].Get()));
            st[nw].Add(qi[i], 1);
            S.insert(st[nw].Get());
            printf("%d%c", *S.rbegin(), i == q ? '\n' : ' ');
        }
    }
    return 0;
}
