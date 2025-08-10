#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        if (n <= 3) {
            cout << "0\n";
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += neigh[i].size() == 1;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int cand = 0;
            for (auto& u : neigh[i])
                cand += neigh[u].size() == 1;
            mx = max(mx, cand);
        }
        cout << cnt - mx << "\n";
    }
    return 0;
}
