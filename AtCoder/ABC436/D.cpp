#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxl = 26;
constexpr int Inf = 1000000000;
const vector<ii> dirs = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

int getId(int r, int c, int m) {
    return r * m + c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    vector<vector<ii>> my(Maxl);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        for (int j = 0; j < m; j++)
            if (islower(B[i][j]))
                my[B[i][j] - 'a'].emplace_back(i, j);
    }
    vector dist(n * m + Maxl, Inf);
    dist[0] = 0;
    deque Q = {0};
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop_front();
        if (v >= n * m) {
            int ind = v - n * m;
            for (auto& p : my[ind]) {
                int u = getId(p.first, p.second, m);
                if (dist[v] < dist[u]) {
                    dist[u] = dist[v];
                    Q.push_front(u);
                }
            }
        } else {
            int r = v / m;
            int c = v % m;
            for (auto& p : dirs) {
                int nr = r + p.first;
                int nc = c + p.second;
                if (0 <= nr && nr < n && 0 <= nc && nc < m && B[nr][nc] != '#') {
                    int u = getId(nr, nc, m);
                    if (dist[v] + 1 < dist[u]) {
                        dist[u] = dist[v] + 1;
                        Q.push_back(u);
                    }
                }
            }
            if (islower(B[r][c])) {
                int u = B[r][c] - 'a' + n * m;
                if (dist[v] + 1 < dist[u]) {
                    dist[u] = dist[v] + 1;
                    Q.push_back(u);
                }
            }
        }
    }
    int res = dist[getId(n - 1, m - 1, m)];
    if (res >= Inf)
        res = -1;
    cout << res << "\n";
    return 0;
}
