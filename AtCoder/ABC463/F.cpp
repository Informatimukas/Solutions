#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr ll mod = 998244353;
constexpr ll inv2 = (mod + 1) / 2;
constexpr int Maxn = 200005;

vector<ll> fac(Maxn), ifac(Maxn);
map<ii, ll> M;

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); }

ll C(int n, int k) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

ll Compute(int t, int m) {
    auto it = M.find({t, m});
    if (it != M.end())
        return it->second;
    ll res = 0;
    for (int i = 0; i <= m; i++)
        res = (res + C(m, i) * Inv(1 + t + i)) % mod;
    M.insert({{t, m}, res});
    return res;
}

struct pos {
    ll p{1}, t{0}, m{0};
    void Merge(const pos& oth) {
        p = p * oth.p % mod;
        t += oth.t;
        m += oth.m;
    }
};

int Compare(int a, int b) {
    if (a == b)
        return 1;
    if (a < b)
        return 0;
    return 2;
}

void Solve(int n, const vector<array<int, 2>>& seq, vector<array<int, 2>>& res, int mx) {
    vector<pos> my(n + 2), L(n + 2), R(n + 2);
    for (int i = 1; i <= n; i++) {
        int st1 = Compare(max(seq[i][0] + 1, seq[i][1]), mx);
        int st2 = Compare(max(seq[i][0], seq[i][1] + 1), mx);
        if (st1 > st2)
            swap(st1, st2);
        if (st1 == 0 && st2 == 1) {
            my[i].p = my[i].p * inv2 % mod;
            my[i].m++;
        } else if (st1 == 1 && st2 == 1)
            my[i].t++;
        else if (st1 == 1 && st2 == 2) {
            my[i].p = my[i].p * inv2 % mod;
            my[i].t += 1 + (min(seq[i][0], seq[i][1]) + 1 == mx);
        } else if (st1 == 2 && st2 == 2)
            my[i].p = 0;
        L[i] = L[i - 1];
        L[i].Merge(my[i]);
    }
    for (int i = n; i > 0; i--) {
        auto cur = L[i - 1];
        cur.Merge(R[i + 1]);
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                auto p = cur;
                p.p = p.p * inv2 % mod;
                int my = seq[i][j] + (j == k);
                if (my != mx)
                    continue;
                int his = seq[i][1 - j] + (j != k);
                if (his > mx)
                    continue;
                if (his == mx)
                    p.t++;
                res[i][j] = (res[i][j] + p.p * Compute(p.t, p.m)) % mod;
            }
        R[i] = R[i + 1];
        R[i].Merge(my[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = Inv(fac[i]);
    }
    int n;
    cin >> n;
    vector<array<int, 2>> seq(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> seq[i][0] >> seq[i][1];
        mx = max(mx, max(seq[i][0], seq[i][1]));
    }
    vector<array<int, 2>> res(n + 1);
    Solve(n, seq, res, mx);
    Solve(n, seq, res, mx + 1);
    for (int i = 1; i <= n; i++)
        cout << res[i][0] << " " << res[i][1] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
