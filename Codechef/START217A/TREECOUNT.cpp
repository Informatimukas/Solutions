#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

vector<int> getWays(const vector<vector<int>>& neigh, int v, int p) {
    vector<array<int, 2>> dp = {{1, 0}};
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        auto got = getWays(neigh, u, v);
        int to = dp.size();
        dp.resize(dp.size() + got.size() - 1);
        for (int i = to - 1; i >= 0; i--) {
            auto arr = dp[i];
            dp[i] = {0, 0};
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < got.size(); k++) {
                    int nj = i > 0 && k > 0 ? 1 : j;
                    int ways = static_cast<ll>(arr[j]) * got[k] % mod;
                    dp[i + k][nj] = (dp[i + k][nj] + ways) % mod;
                }
        }
    }
    vector<int> res(dp.size() + 1);
    for (int i = 0; i < dp.size(); i++) {
        res[i] = (res[i] + dp[i][0]) % mod;
        res[i + 1] = (res[i + 1] + dp[i][0]) % mod;
        res[i + 1] = (res[i + 1] + 2ll * dp[i][1]) % mod;
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
        int n;
        cin >> n;
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        auto res = getWays(neigh, 1, 0);
        for (int i = 1; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
