#include <bits/stdc++.h>
using namespace std;

void Traverse(int v, int p, const vector<vector<int>>& neigh, vector<int>& dist, vector<vector<int>>& bydist,
    vector<int>& par) {
    par[v] = p;
    bydist[dist[v]].push_back(v);
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        dist[u] = dist[v] + 1;
        Traverse(u, v, neigh, dist, bydist, par);
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
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        vector dist(n + 1, 0);
        vector<vector<int>> bydist(n + 1);
        vector par(n + 1, 0);
        Traverse(1, 0, neigh, dist, bydist, par);
        int res = 0;
        for (int i = 0; i < n; i++)
            if (bydist[i + 1].empty())
                res = max(res, static_cast<int>(bydist[i].size()));
            else {
                int v = par[bydist[i + 1][0]];
                for (auto u : bydist[i + 1])
                    if (par[u] != v)
                        v = -1;
                if (v != -1)
                    res = max(res, 1 + static_cast<int>(max(bydist[i].size() - 1, bydist[i + 1].size())));
                else res = max(res, static_cast<int>(max(bydist[i].size(), bydist[i + 1].size())));
            }
        cout << res << "\n";
    }
    return 0;
}
