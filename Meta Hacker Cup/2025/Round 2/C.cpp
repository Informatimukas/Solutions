#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, k, m;
        cin >> n >> k >> m;
        vector mypos(n + 1, vector<ii>());
        vector tram(m, set<ii>());
        vector dist(n + 1, -1);
        for (int i = 0; i < m; i++) {
            int l;
            cin >> l;
            for (int j = 0; j < l; j++) {
                int x;
                cin >> x;
                mypos[x].emplace_back(i, j);
                tram[i].emplace(j, x);
            }
        }
        dist[1] = 0;
        queue<int> Q;
        Q.push(1);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (auto& [tid, tind] : mypos[v]) {
                auto it = tram[tid].lower_bound({tind, 0});
                while (it != tram[tid].end() && it->first - tind <= k) {
                    if (dist[it->second] == -1) {
                        dist[it->second] = dist[v] + 1;
                        Q.push(it->second);
                    }
                    tram[tid].erase(it++);
                }
            }
        }
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += static_cast<ll>(i) * dist[i];
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}