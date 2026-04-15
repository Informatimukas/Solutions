#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;

struct pos {
    ll ways{0}, sum{0};
};

pos Join(const pos& a, const pos& b, ll lvl) {
    pos res;
    res.ways = a.ways * b.ways % mod;
    res.sum = (a.ways * b.sum + a.sum * b.ways + a.ways * b.ways % mod * 2ll * lvl) % mod;
    return res;
}

pos Add(const pos& a, const pos& b) {
    return {(a.ways + b.ways) % mod, (a.sum + b.sum) % mod};
}

vector<pos> Solve(int v, int p, const vector<vector<int>>& neigh) {
    int lvl = neigh.size() - 1;
    vector dp(lvl, array<pos, 2>{});
    dp[0][1] = {1, 0};
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        auto got = Solve(u, v, neigh);
        pos tail;
        for (int i = lvl - 1; i >= 0; i--) {
            tail.sum = (tail.sum + tail.ways) % mod;
            pos ntail = Add(tail, got[i]);
            dp[i][1] = Join(dp[i][1], ntail, i);
            dp[i][1] = Add(dp[i][1], Join(dp[i][0], got[i], i));
            dp[i][1] = Add(dp[i][1], got[i]);
            dp[i][0] = Join(dp[i][0], tail, i);
            dp[i][0] = Add(dp[i][0], tail);
            tail = ntail;
        }
    }
    vector<pos> res(lvl);
    for (int i = lvl - 1; i > 0; i--)
        res[i] = dp[i - 1][1];
    cout << "v = " << v << endl;
    for (int i = 0; i < lvl; i++)
        cout << "res[" << i << "] = " << res[i].ways << ", " << res[i].sum << endl;
    cout << endl;
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
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        auto ans = Solve(1, 0, neigh);
        ll res = 0;
        for (auto x : ans)
            res = (res + x.sum) % mod;
        cout << res << "\n";
    }
    return 0;
}
