#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxm = 18;
constexpr int Maxk = 20;

struct pos {
    array<int, Maxk> mask{};
    array<ii, Maxk> seq{};
    int len{0};
    void Add(const ii& p) {
        int cur = p.first;
        for (int i = Maxk - 1; i >= 0; i--)
            if (cur & 1 << i) {
                if (mask[i])
                    cur ^= mask[i];
                else {
                    mask[i] = cur;
                    seq[len++] = {cur, p.second};
                    break;
                }
            }
    }
};

pos Union(const pos& a, const pos& b) {
    pos c = a;
    for (int i = 0; i < b.len; i++)
        c.Add(b.seq[i]);
    return c;
}

int getMask(const pos& a, int ind) {
    int b = a.len - 1;
    int res = 0;
    for (int i = Maxk - 1; i >= 0; i--)
        if (a.mask[i]) {
            if (static_cast<bool>(res & 1 << i) != static_cast<bool>(ind & 1 << b))
                res ^= a.mask[i];
            --b;
        }
    return res;
}

int getInd(const pos& a, int value) {
    int res = 1 << Maxk, cand = 0;
    int b = a.len - 1;
    int cur = 0;
    for (int i = Maxk - 1; i >= 0; i--)
        if (a.mask[i]) {
            if (value & 1 << i) {
                cand |= 1 << b;
                if (!(cur & 1 << i))
                    cur ^= a.mask[i];
            } else {
                res = cand | 1 << b;
                if (cur & 1 << i)
                    cur ^= a.mask[i];
            }
            --b;
        } else if (static_cast<bool>(value & 1 << i) && !static_cast<bool>(cur & 1 << i))
            break;
        else if (!static_cast<bool>(value & 1 << i) && static_cast<bool>(cur & 1 << i)) {
            res = cand;
            break;
        }
    return res;
}

void Create(vector<pos>& st, int v, int l, int r, const vector<int>& a) {
    if (l == r)
        st[v].Add({a[l], l});
    else {
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
    return Union(Get(st, 2 * v, l, m, a, m), Get(st, 2 * v + 1, m + 1, r, m + 1, b));
}

bool Solve(int l, int r, int n, const vector<pos>& st) {
    pos tot = Get(st, 1, 1, n, l, r);
    pos cur;
    cur.Add(tot.seq[0]);
    int ind = 0;
    for (int i = 1; i < tot.len; i++) {
        ind += tot.seq[i].second - tot.seq[i - 1].second - 1;
        if (ind >= 1 << cur.len)
            return false;
        int mask = getMask(cur, ind);
        cur.Add(tot.seq[i]);
        ind = getInd(cur, mask);
    }
    ind += r - tot.seq[tot.len - 1].second;
    return ind < 1 << cur.len;
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
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<pos> st(4 * (n + 1));
        Create(st, 1, 1, n, a);
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << (Solve(l, r, n, st) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
