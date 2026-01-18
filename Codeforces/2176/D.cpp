#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<lli>> neigh(n + 1);
        map<lli, int> M;
        int res = 0;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            neigh[u].emplace_back(a[v], v);
            lli p = {a[u] + a[v], v};
            M[p] = (M[p] + 1) % mod;
        }
        for (int i = 1; i <= n; i++)
            ranges::sort(neigh[i], greater());
        for (auto it = M.begin(); it != M.end(); ++it) {
            auto& [cost, v] = it->first;
            int add = it->second;
            res = (res + add) % mod;
            while (!neigh[v].empty() && neigh[v].back().first < cost)
                neigh[v].pop_back();
            while (!neigh[v].empty() && neigh[v].back().first == cost) {
                int u = neigh[v].back().second;
                lli p = {a[v] + a[u], u};
                M[p] = (M[p] + add) % mod;
                neigh[v].pop_back();
            }
        }
        cout << res << "\n";
    }
    return 0;
}
