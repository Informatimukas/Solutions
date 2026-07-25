#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxm = 1000006;
constexpr int Maxd = 4;

int Count(int v, int p, int n, const vector<vector<int>>& neigh, vector<vector<int>>& counts) {
    int res = 1;
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        int sz = Count(u, v, n, neigh, counts);
        counts[v].push_back(sz);
        res += sz;
    }
    counts[v].push_back(n - res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector good(Maxm, false);
    for (int i = 1; i * i < Maxm; i++)
        good[i * i] = true;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<int>> neigh(n + 1);
        vector<vector<int>> counts(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        Count(1, 0, n, neigh, counts);
        ll res = 0;
        for (int i = 1; i <= n; i++)
            if (good[a[i]]) {
                array<ll, Maxd> dp{};
                dp[0] = 1;
                for (auto c : counts[i])
                    for (int j = Maxd - 2; j >= 0; j--)
                        dp[j + 1] += dp[j] * c;
                res += dp[2] + dp[3];
            }
        cout << res << "\n";
    }
    return 0;
}
