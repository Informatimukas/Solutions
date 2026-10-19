#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;

struct pos {
    bool fl{false};
    int res{0};
};

void downOn(vector<pos>& st, int v) {
    st[v].fl = true;
    st[v].res = 0;
}

void Down(vector<pos>& st, int v) {
    if (st[v].fl) {
        downOn(st, 2 * v);
        downOn(st, 2 * v + 1);
        st[v].fl = false;
    }
}

void Add(vector<pos>& st, int v, int l, int r, int x, int val) {
    if (l == r) {
        st[v].res = (st[v].res + val) % mod;
        return;
    }
    Down(st, v);
    int m = (l + r) / 2;
    if (x <= m)
        Add(st, 2 * v, l, m, x, val);
    else Add(st, 2 * v + 1, m + 1, r, x, val);
    st[v].res = (st[2 * v].res + st[2 * v + 1].res) % mod;
}

void Clear(vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        downOn(st, v);
    else {
        Down(st, v);
        int m = (l + r) / 2;
        if (a <= m)
            Clear(st, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b)
            Clear(st, 2 * v + 1, m + 1, r, max(m + 1, a), b);
        st[v].res = (st[2 * v].res + st[2 * v + 1].res) % mod;
    }
}

int Get(vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v].res;
    Down(st, v);
    int res = 0;
    int m = (l + r) / 2;
    if (a <= m)
        res = (res + Get(st, 2 * v, l, m, a, min(m, b))) % mod;
    if (m + 1 <= b)
        res = (res + Get(st, 2 * v + 1, m + 1, r, max(m + 1, a), b)) % mod;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> forb(n + 1);
        vector mn(n + 1, n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < a; j++) {
                int lef = j * i, rig = min(n, (j + 1) * i);
                mn[rig] = min(mn[rig], lef);
            }
            int lef = a * i, rig = min(n, (a + 1) * i);
            if (lef < rig) {
                forb[lef]++;
                forb[rig]--;
            }
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += forb[i];
            forb[i] = cur > 0;
        }
        int has = 1;
        vector<pos> st(4 * (n + 1));
        for (int i = 0; i <= n; i++) {
            if (mn[i] <= i) {
                has = 0;
                if (0 < mn[i])
                    Clear(st, 1, 0, n - 1, 0, mn[i - 1]);
            }
            if (i < n && !forb[i]) {
                int got = i > 0 ? Get(st, 1, 0, n - 1, 0, i - 1) : 0;
                got = (got + has) % mod;
                Add(st, 1, 0, n - 1, i, got);
            }
        }
        has = (has + Get(st, 1, 0, n - 1, 0, n - 1)) % mod;
        cout << has << "\n";
    }
    return 0;
}
