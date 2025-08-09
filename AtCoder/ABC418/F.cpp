#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
constexpr int Maxd = 2;

using ll = long long;
using ii = pair<int, int>;

struct pos {
    ii lef, rig;
    array<array<int, Maxd>, Maxd> dp;
    pos() : lef{-1, -1}, rig{-1, -1}, dp() {
        for (auto &a: dp)
            fill_n(a.begin(), Maxd, 0);
    }
};

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < 0 || k < 0 || k > n) return 0;
    return static_cast<ll>(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int getEnding(int siz, const vector<int>& fib) {
    if (siz < 0) return 1;
    return fib[siz];
}

int getInBetween(int lef, int f1, int rig, int f2, int cnt,
    const vector<int>& fac, const vector<int>& ifac) {
    if (cnt < 0) return 0;
    if (lef + 1 == rig) {
        if (f1 == 0 || f2 == 0)
            return cnt == 0;
        return 0;
    }
    if (lef + 2 == rig) {
        if (f1 == 1 || f2 == 1)
            return cnt == 0;
        return cnt <= 1;
    }
    lef += 1 + f1;
    rig -= (1 + f2);
    if (cnt == 0) return 1;
    int s = rig - lef + 1;
    return C(s - (cnt - 1), cnt, fac, ifac);
}

pos Union(const pos& a, const pos& b, const vector<int>& fac, const vector<int>& ifac) {
    if (a.lef.first == -1)
        return b;
    if (b.lef.first == -1)
        return a;
    pos c;
    c.lef = a.lef;
    c.rig = b.rig;
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++)
            for (int i2 = 0; i2 < Maxd; i2++)
                for (int j2 = 0; j2 < Maxd; j2++)
                    c.dp[i][j] = (c.dp[i][j] +
                        static_cast<ll>(a.dp[i][i2]) * b.dp[j2][j] % mod *
                        getInBetween(a.rig.first, i2, b.lef.first, j2,
                        b.lef.second - a.rig.second - j2,
                            fac, ifac)) % mod;
    return c;
}

void Update(vector<pos> &st, int v, int l, int r, int x, int val,
    const vector<int>& fac, const vector<int>& ifac) {
    if (l == r)
        if (val == -1)
            st[v].lef = st[v].rig = {-1, -1};
        else {
            st[v].lef = st[v].rig = {l, val};
            st[v].dp[0][0] = 1;
            st[v].dp[1][1] = x > 0;
            st[v].dp[0][1] = st[v].dp[1][0] = 0;
        }
    else {
        int m = l + r >> 1;
        if (x <= m) Update(st, 2 * v, l, m, x, val, fac, ifac);
        else Update(st, 2 * v + 1, m + 1, r, x, val, fac, ifac);
        st[v] = Union(st[2 * v], st[2 * v + 1], fac, ifac);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> fac(n + 1), ifac(n + 1);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
        ifac[i] = Inv(fac[i]);
    }
    vector<int> fib(n + 1);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i <= n; i++)
        fib[i] = (fib[i - 2] + fib[i - 1]) % mod;
    vector<pos> st(4 * (n + 1) + 1);
    Update(st, 1, 0, n, 0, 0, fac, ifac);
    while (q--) {
        int x, y;
        cin >> x >> y;
        Update(st, 1, 0, n, x, y, fac, ifac);
        auto& nod = st[1];
        int res = 0;
        if (nod.lef.first == -1)
            res = getEnding(n, fib);
        else {
            for (int i = 0; i < Maxd; i++)
                for (int j = 0; j < Maxd; j++)
                    res = (res + static_cast<ll>(nod.dp[i][j]) *
                        getEnding(n - nod.rig.first - j, fib)) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
