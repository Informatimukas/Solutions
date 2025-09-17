#include <bits/stdc++.h>
using namespace std;

void Count(int v, int p, const vector<vector<array<int, 3>>>& neigh, vector<int>& cnt) {
    cnt[v] = 1;
    for (auto& u : neigh[v]) {
        if (u[0] == p) continue;
        Count(u[0], v, neigh, cnt);
        cnt[v] += cnt[u[0]];
    }
}

void Solve(int v, int p, const vector<vector<array<int, 3>>>& neigh, const vector<int>& cnt,
    int lef, int rig, vector<int>& res) {
    for (auto& u : neigh[v]) {
        if (u[0] == p) continue;
        bool small = (v < u[0]) ^ (u[1] > u[2]);
        int nlef, nrig;
        if (small) {
            nrig = rig;
            nlef = rig - cnt[u[0]] + 1;
            rig -= cnt[u[0]];
        } else {
            nlef = lef;
            nrig = lef + cnt[u[0]] - 1;
            lef += cnt[u[0]];
        }
        Solve(u[0], v, neigh, cnt, nlef, nrig, res);
    }
    res[v] = lef;
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
        vector<vector<array<int, 3>>> neigh(n + 1);
        vector<int> res(n + 1), cnt(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            neigh[u].push_back({v, x, y});
            neigh[v].push_back({u, x, y});
        }
        Count(1, 0, neigh, cnt);
        Solve(1, 0, neigh, cnt, 1, n, res);
        for (int i = 1; i <= n; i++)
            cout << res[i] << (i + 1 <= n? ' ': '\n');
    }
    return 0;
}
