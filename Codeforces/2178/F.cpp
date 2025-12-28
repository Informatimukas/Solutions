#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

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

int Count(const vector<vector<int>>& neigh, int v, int p, vector<int>& comp) {
    int s = 1;
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        s += Count(neigh, u, v, comp);
    }
    if (v != 1 && s % 2 == 0) {
        comp.push_back(s);
        s = 0;
    }
    return s;
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
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        vector<int> comp;
        int fir = Count(neigh, 1, 0, comp);
        if (comp.empty()) {
            cout << "1\n";
            continue;
        }
        ll cur = fir;
        for (int i = 1; i <= comp.size() - 1; i++)
            cur = cur * i % mod;
        for (auto& s : comp)
            cur = cur * s % mod * s % mod;
        ll res = 0;
        for (auto& s : comp)
            res = (res + cur * Inv(s)) % mod;
        cout << res << "\n";
    }
    return 0;
}
