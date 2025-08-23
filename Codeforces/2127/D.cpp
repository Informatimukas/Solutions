#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

struct pos {
    int ways;
    bool spec;
};

pos Solve(int v, int c, vector<int>& col, const vector<int>& fac,
    const vector<vector<int>>& neigh) {
    if (col[v] != 0)
        return col[v] == c? pos{1, false} : pos{0, false};
    col[v] = c;
    int cnt = 0;
    int ways = 1;
    bool spec = false;
    int othCnt = 0, specCnt = 0;
    for (auto& u : neigh[v]) {
        auto got = Solve(u, -c, col, fac, neigh);
        ways = static_cast<ll>(ways) * got.ways % mod;
        spec |= got.spec;
        if (neigh[u].size() > 1) specCnt++;
        else othCnt++;
    }
    if (specCnt > 2) return {0, false};
    if (specCnt && neigh[v].size() > 1) spec = true;
    ways = static_cast<ll>(ways) * fac[othCnt] % mod;
    return {ways, spec};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector neigh(n + 1, vector<int>());
        vector col(n + 1, 0);
        vector<int> fac(n + 1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
        int ways = 1, comp = 0;
        for (int i = 1; i <= n; i++)
            if (col[i] == 0) {
                pos got = Solve(1, 1, col, fac, neigh);
                ways = static_cast<ll>(ways) * got.ways % mod * 2 % mod;
                if (got.spec)
                    ways = 2ll * ways % mod;
                comp++;
            }
        ways = static_cast<ll>(ways) * fac[comp] % mod;
        cout << ways << "\n";
    }
    return 0;
}
