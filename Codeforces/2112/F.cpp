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
    vector def(n + 1, vector(n + 1, Inf));
    for (int i = 1; i <= n; i++)
        dist[i][i] = def[i][i] = 0;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        dist[y][x] = def[y][x] = min(dist[y][x], z);
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
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mx[j] = min(mx[j], a[i] + def[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) if (dist[i][j] < def[i][j])
                mn[j] = min(mn[j], a[i] - k + dist[i][j]);
        for (int i = 1; i <= n; i++)
            cout << (mn[i] < mx[i]);
        cout << "\n";
    }
    return 0;
}
