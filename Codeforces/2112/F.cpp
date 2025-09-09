#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector dist(n + 1, vector(n + 1, Inf));
    vector tk(n + 1, vector(n + 1, false));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        tk[i][i] = true;
    }
    vector<vector<int>> E;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        E.push_back({x, y, z});
        dist[y][x] = min(dist[y][x], z);
        tk[y][x] = true;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> a(n + 1), mx(n + 1), mn(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mx[i] = mn[i] = a[i];
        }
        for (auto& e : E)
            mx[e[0]] = min(mx[e[0]], a[e[1]] + e[2]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) if (!tk[i][j] && dist[i][j] < Inf)
                mn[j] = min(mn[j], a[i] - k + dist[i][j]);
        for (int i = 1; i <= n; i++)
            cout << (mn[i] < mx[i]);
        cout << "\n";
    }
    return 0;
}
