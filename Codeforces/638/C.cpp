#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Solve(int v, int p, int tk, const vector<vector<ii>>& neigh, vector<vector<int>>& res) {
    int cur = 0;
    for (auto& [u, e] : neigh[v]) {
        if (u == p)
            continue;
        if (cur == tk)
            ++cur;
        res[cur].push_back(e);
        Solve(u, v, cur, neigh, res);
        cur++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ii>> neigh(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].emplace_back(b, i);
        neigh[b].emplace_back(a, i);
    }
    int r = 1;
    for (int i = 2; i <= n; i++)
        if (neigh[i].size() > neigh[r].size())
            r = i;
    vector<vector<int>> res(neigh[r].size());
    for (int i = 0; i < neigh[r].size(); i++) {
        res[i].push_back(neigh[r][i].second);
        Solve(neigh[r][i].first, r, i, neigh, res);
    }
    cout << res.size() << "\n";
    for (auto& V : res) {
        cout << V.size();
        for (auto x : V)
            cout << " " << x;
        cout << "\n";
    }
    return 0;
}
