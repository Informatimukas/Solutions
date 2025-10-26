#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            neigh[y].push_back(x);
        }
        vector<int> p(n + 1), inp(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            inp[p[i]] = i;
        }
        int mx = 0;
        vector res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            res[i] = mx;
            int v = inp[i];
            for (auto& u : neigh[v])
                res[i] = max(res[i], res[p[u]] + 1);
            mx = max(mx, res[i]);
        }
        mx++;
        cout << n - mx << "\n";
    }
    return 0;
}
