#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 200005;
constexpr ll mod = 998244353;

vector<ll> fac(Maxn), ifac(Maxn);

ll toPower(ll a, int p) {
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

void Fill(int v, const vector<vector<int>>& neigh, vector<bool>& vis, vector<int>& seq) {
    if (vis[v])
        return;
    vis[v] = true;
    seq.push_back(v);
    for (auto u : neigh[v])
        Fill(u, neigh, vis, seq);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = i * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> neigh(n);
    vector vis(n, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    ll mult = (mod + 1) / 2;
    ll res = 1;
    for (int i = 0; i < n; i++)
        if (!vis[i]) {
            vector<int> seq;
            Fill(i, neigh, vis, seq);
            array<int, 26> cnt{};
            for (auto ind : seq)
                cnt[s[ind] - 'a']++;
            int rem = seq.size();
            for (auto c : cnt) {
                res = res * C(rem, c) % mod;
                rem -= c;
                if (c > 1)
                    mult = 1;
            }
        }
    res = res * mult % mod;
    cout << res << "\n";
    return 0;
}
