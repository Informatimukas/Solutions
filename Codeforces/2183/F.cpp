#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a;
        cin >> a;
        vector<vector<int>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }

    }
    return 0;
}
