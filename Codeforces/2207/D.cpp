#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

void addBest(array<int, 2>& best, int val) {
    if (val < best[0])
        best[1] = best[0], best[0] = val;
    else if (val < best[1])
        best[1] = val;
}

int Solve(int v, int p, int k, const vector<vector<int>>& neigh) {
    array best = {Inf, Inf};
    bool leaf = true;
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        leaf = false;
        addBest(best, Solve(u, v, k, neigh) + 1);
    }
    if (leaf || best[0] + best[1] <= k + 1)
        return 0;
    return best[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, v;
        cin >> n >> k >> v;
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        cout << (Solve(v, 0, k, neigh) > 0? "NO" : "YES") << "\n";
    }
    return 0;
}
