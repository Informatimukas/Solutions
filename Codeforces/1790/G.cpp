#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Inf = 1000000000;

void Fill(int v, const vector<vector<int>>& neigh, vector<bool>& rep, const vector<bool>& bonus) {
    if (!bonus[v] || rep[v])
        return;
    rep[v] = true;
    for (auto u : neigh[v])
        Fill(u, neigh, rep, bonus);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int p, b;
        cin >> p >> b;
        vector<int> tokens(p);
        for (auto& x : tokens)
            cin >> x;
        vector<bool> bonus(n + 1);
        bonus[1] = true;
        for (int i = 0; i < b; i++) {
            int x;
            cin >> x;
            bonus[x] = true;
        }
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        vector dist(n + 1, Inf);
        dist[1] = 0;
        queue<int> Q;
        Q.push(1);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (auto u : neigh[v])
                if (bonus[u] && dist[v] + 1 < dist[u]) {
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
        }
        vector<bool> rep(n + 1);
        for (int i = 1; i <= n; i++)
            for (auto u : neigh[i])
                if (bonus[i] && bonus[u])
                    Fill(i, neigh, rep, bonus);
        ll sum = 0;
        vector<int> my(p);
        for (int i = 0; i < p; i++) {
            for (auto u : neigh[tokens[i]])
                if (rep[u]) my[i] = Inf;
                else if (bonus[u])
                    my[i] = max(my[i], 1);
            sum += my[i];
        }
        bool ok = false;
        for (int i = 0; i < p; i++) {
            int d = dist[tokens[i]];
            for (auto u : neigh[tokens[i]])
                d = min(d, 1 + dist[u]);
            if (d < Inf && d <= sum - my[i] + 1) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
