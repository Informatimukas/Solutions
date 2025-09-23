#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Colour(int v, vector<array<bool, 2>>& on, vector<int>& goodIn,
    const vector<vector<int>>& neigh) {
    queue<ii> Q;
    for (int pl = 0; pl < 2; pl++)
        if (!on[v][pl]) {
            on[v][pl] = true;
            Q.emplace(v, pl);
        }
    while (!Q.empty()) {
        ii p = Q.front();
        Q.pop();
        if (p.second == 0)
            for (auto& u : neigh[p.first]) {
                if (!on[u][1]) {
                    on[u][1] = true;
                    Q.emplace(u, 1);
                }
            }
        else for (auto& u : neigh[p.first])
            if (!on[u][0] && --goodIn[u] == 0) {
                on[u][0] = true;
                Q.emplace(u, 0);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector on(n + 1, array<bool, 2>());
        vector goodIn(n + 1, 0);
        vector neigh(n + 1, vector<int>());
        while (m--) {
            int u, v;
            cin >> u >> v;
            neigh[v].push_back(u);
            goodIn[u]++;
        }
        while (q--) {
            int x, y;
            cin >> x >> y;
            if (x == 1)
                Colour(y, on, goodIn, neigh);
            else cout << (on[y][0] ? "NO" : "YES") << '\n';
        }
    }
    return 0;
}