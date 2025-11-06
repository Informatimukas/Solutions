#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Inf = 1000000007;

struct UnionSet {
    vector<int> par, val;
    vector<vector<int>> neigh;
    UnionSet(int n): par(n + 1), neigh(n + 1), val(n + 1, Inf) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    void unionSet(int a, int b, int c, int w) {
        a = getPar(a), b = getPar(b);
        val[c] = w;
        neigh[c].push_back(a);
        if (b != a)
            neigh[c].push_back(b);
        par[a] = par[b] = c;
    }
};

int Traverse(int v, int n, UnionSet& us, const vector<int>& deg, int best, ll& res) {
    best = min(best, us.val[v]);
    int cnt = v <= n && deg[v] % 2;
    for (auto& u : us.neigh[v]) {
        cnt += Traverse(u, n, us, deg, best, res);
        if (cnt >= 2) {
            cnt -= 2;
            res += best;
        }
    }
    return cnt;
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
        UnionSet us(n + m);
        vector deg(n + 1, 0);
        ll res = 0;
        for (int i = 1; i <= m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            res += w;
            deg[a]++;
            deg[b]++;
            us.unionSet(a, b, n + i, w);
        }
        int root = us.getPar(1);
        Traverse(root, n, us, deg, Inf, res);
        cout << res << "\n";
    }
    return 0;
}
