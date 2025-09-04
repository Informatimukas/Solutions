#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void addBest(array<ii, 2>& best, const ii& cand) {
    if (cand > best[0]) {
        best[1] = best[0];
        best[0] = cand;
    } else if (cand > best[1])
        best[1] = cand;
}

ii Traverse(int v, int p, const vector<vector<int>>& neigh, vector<array<ii, 2>>& best) {
    ii res;
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        res = max(res, Traverse(u, v, neigh, best));
        addBest(best[v], {best[u][0].first + 1, u});
    }
    res = max(res, {best[v][0].first + best[v][1].first, v});
    return res;
}

vector<int> Solve(int v, int p, const vector<vector<int>>& neigh, const vector<array<ii, 2>>& best) {
    if (p == 0) {
        for (auto& u : neigh[v])
            if (u != best[v][0].second && u != best[v][1].second)
                return {best[v][0].second, v, u};
        for (auto& u : neigh[v]) {
            auto got = Solve(u, v, neigh, best);
            if (!got.empty())
                return got;
        }
        return {};
    }
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        if (u != best[v][0].second)
            return {best[v][0].second, v, u};
        auto got = Solve(u, v, neigh, best);
        if (!got.empty())
            return got;
    }
    return {};
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
        vector best(n + 1, array<ii, 2>());
        int root = Traverse(1, 0, neigh, best).second;
        auto got = Solve(root, 0, neigh, best);
        if (got.empty())
            cout << "-1\n";
        else cout << got[0] << " " << got[1] << " " << got[2] << "\n";
    }
    return 0;
}
