#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ill = pair<int, ll>;

constexpr ll mod = 998244353;

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

ill Solve(int v, int p, const vector<vector<int>>& neigh, vector<ll>& res) {
    ill cur = {mod, mod};
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        cur = min(cur, Solve(u, v, neigh, res));
    }
    if (cur.first == mod)
        return {0, 0};
    cur.first++;
    res[v] = Inv((2 - cur.second + mod) % mod);
    cur.second = res[v];
    return cur;
}

void Traverse(int v, int p, const vector<vector<int>>& neigh, vector<ll>& res) {
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        res[u] = res[u] * res[v] % mod;
        Traverse(u, v, neigh, res);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> neigh(n + 1);
        vector<ll> res(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        res[1] = 1;
        for (auto v : neigh[1])
            Solve(v, 1, neigh, res);
        Traverse(1, 0, neigh, res);
        for (int i = 1; i <= n; i++)
            cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
