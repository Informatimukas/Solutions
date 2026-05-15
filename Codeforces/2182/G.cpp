#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

struct pos {
    vector<ll> ways;
    ll mult{1};
    ll good{0};
};

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

void Merge(pos& a, pos& b) {
    if (a.ways.size() < b.ways.size())
        swap(a, b);
    ll inv = Inv(a.mult);
    for (int i = 1; i <= b.ways.size(); i++) {
        int inda = a.ways.size() - i;
        int indb = b.ways.size() - i;
        a.ways[inda] = (a.ways[inda] + b.ways[indb] * b.mult % mod * inv) % mod;
    }
    a.good = (a.good + b.good * b.mult % mod * inv) % mod;
}

pos Solve(int v, const vector<vector<int>>& neigh, const vector<ll>& fac, int k) {
    pos res;
    if (neigh[v].empty()) {
        res.ways = {1};
        res.good = 1;
        return res;
    }
    vector<pos> got(neigh[v].size());
    ll allgood = 1;
    int zeroes = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        got[i] = Solve(u, neigh, fac, k);
        got[i].ways.push_back(0);
        if (got[i].ways.size() > k)
            got[i].good = (got[i].good - got[i].ways[got[i].ways.size() - k - 1] + mod) % mod;
        ll my = got[i].good * got[i].mult % mod;
        if (my == 0)
            zeroes++;
        else allgood = allgood * my % mod;
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        ll my = got[i].good * got[i].mult % mod;
        if (my == 0)
            zeroes--;
        else allgood = allgood * Inv(my) % mod;
        ll nmult = zeroes ? 0 : allgood;
        got[i].mult = got[i].mult * nmult % mod * fac[neigh[v].size() - 1] % mod;
        if (got[i].mult)
            Merge(res, got[i]);
        if (my == 0)
            zeroes++;
        else allgood = allgood * my % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> fac(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i % mod;
        vector<vector<int>> neigh(n + 1);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
        }
        auto res = Solve(1, neigh, fac, k);
        ll ans = 0;
        for (auto x : res.ways)
            ans = (ans + x) % mod;
        ans = ans * res.mult % mod;
        cout << ans << "\n";
    }
    return 0;
}
