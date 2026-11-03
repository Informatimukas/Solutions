#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Solve(int v, int p, int cur, int cols, const vector<vector<ii>>& neigh, vector<int>& res) {
    int my = 1;
    for (auto& [u, ind] : neigh[v]) {
        if (u == p)
            continue;
        if (my == cur)
            ++my;
        res[ind] = min(my++, cols);
        Solve(u, v, res[ind], cols, neigh, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<ii>> neigh(n + 1);
    vector<ii> seq;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].emplace_back(b, i);
        neigh[b].emplace_back(a, i);
    }
    vector<int> res(n - 1);
    for (int i = 1; i <= n; i++)
        seq.emplace_back(neigh[i].size(), i);
    ranges::sort(seq, greater());
    int cols = seq[k].first;
    Solve(1, 0, 0, cols, neigh, res);
    cout << cols << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
