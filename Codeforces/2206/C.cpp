#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;
using lli = pair<ll, int>;

vector<int> Solve(const vector<vector<ii>>& neigh, const vector<int>& w) {
    vector<int> S;
    vector vis(neigh.size(), false);
    priority_queue<lli> Q;
    Q.emplace(0, 1);
    while (!Q.empty()) {
        auto [dist, u] = Q.top();
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        S.push_back(u);
        for (auto& [v, ind] : neigh[u]) {
            int add = w[ind];
            Q.emplace(dist + add, v);
        }
    }
    return S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<ii>> neigh(n + 1);
    vector<int> inseq(n + 1);
    vector<int> seq(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        neigh[u].emplace_back(v, i);
        neigh[v].emplace_back(u, i);
    }
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
        inseq[seq[i]] = i;
    }
    vector<int> res(m);
    for (int i = 1; i <= n; i++) {
        ranges::sort(neigh[i], {}, [&](auto&& x) { return inseq[x.first]; });
        for (int j = 0; j < neigh[i].size(); j++)
            if (inseq[i] < inseq[neigh[i][j].first])
                res[neigh[i][j].second] = neigh[i].size() - j;
    }
    if (Solve(neigh, res) != seq) {
        cout << "impossible\n";
        return 0;
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
