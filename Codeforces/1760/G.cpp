#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Traverse(int v, int p, const vector<vector<ii>>& neigh, vector<int>& xr) {
    for (auto& [u, cost] : neigh[v]) {
        if (u == p)
            continue;
        xr[u] = xr[v] ^ cost;
        Traverse(u, v, neigh, xr);
    }
}

bool canSelect(int v, int p, int b, const vector<vector<ii>>& neigh, const vector<int>& xr,
    const set<int>& S) {
    if (S.contains(xr[v]))
        return true;
    return ranges::any_of(neigh[v], [&](const auto& pr) {
        int u = pr.first;
        return u != p && u != b && canSelect(u, v, b, neigh, xr, S);
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector neigh(n + 1, vector<ii>());
        vector xr(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v, cost;
            cin >> u >> v >> cost;
            neigh[u].emplace_back(v, cost);
            neigh[v].emplace_back(u, cost);
        }
        Traverse(1, 0, neigh, xr);
        set<int> S;
        for (int i = 1; i <= n; i++)
            if (i != b)
                S.insert(xr[i] ^ xr[a] ^ xr[b]);
        if (canSelect(a, 0, b, neigh, xr, S))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}