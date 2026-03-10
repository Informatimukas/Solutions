#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    ll all{0};
    vector<ll> V;
};

ll Solve(pos& a, const pos& b) {
    ll res = 0;
    ll cura = a.all, curb = b.all;
    for (int z = 1; z <= b.V.size(); z++) {
        int i = a.V.size() - z, j = b.V.size() - z;
        res += (z - 1) * (a.V[i] * curb + b.V[j] * cura);
        cura -= a.V[i];
        curb -= b.V[j];
        a.V[i] += b.V[j];
    }
    a.all += b.all;
    return res;
}

pos Traverse(const vector<vector<int>>& tneigh, int v, ll& ans) {
    pos res;
    res.all = 1;
    res.V = {1};
    for (auto u : tneigh[v]) {
        pos got = Traverse(tneigh, u, ans);
        got.V.push_back(0);
        if (res.V.size() < got.V.size())
            swap(res, got);
        ans += Solve(res, got);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> neigh(n + 1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
        }
        vector best(n + 1, 1000000000);
        vector<vector<int>> tneigh(n + 1);
        best[n] = 0;
        for (int i = n - 1; i > 0; i--) {
            neigh[i].push_back(i + 1);
            ranges::sort(neigh[i], greater());
            int p = n;
            for (auto u : neigh[i])
                if (best[u] + 1 < best[i]) {
                    best[i] = best[u] + 1;
                    p = u;
                }
            tneigh[p].push_back(i);
        }
        ll res = 0;
        Traverse(tneigh, n, res);
        cout << res << "\n";
    }
    return 0;
}
