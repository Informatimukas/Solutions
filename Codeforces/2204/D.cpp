#include <bits/stdc++.h>
using namespace std;

int Count(const vector<vector<int>>& neigh, int v, vector<bool>& tk) {
    if (tk[v])
        return 0;
    tk[v] = true;
    int res = 1;
    for (auto u : neigh[v])
        res += Count(neigh, u, tk);
    return res;
}

bool Visit(const vector<vector<int>>& neigh, int v, int c, vector<int>& col, int& res1, int& res2) {
    if (col[v])
        return col[v] == c;
    col[v] = c;
    res1++;
    for (auto u : neigh[v])
        if (!Visit(neigh, u, -c, col, res2, res1))
            return false;
    return true;
}

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
            int v, u;
            cin >> v >> u;
            neigh[v].push_back(u);
            neigh[u].push_back(v);
        }
        vector tk(n + 1, false);
        vector col(n + 1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (!tk[i]) {
                Count(neigh, i, tk);
                int res1 = 0, res2 = 0;
                if (Visit(neigh, i, 1, col, res1, res2))
                    res += max(res1, res2);
            }
        cout << res << "\n";
    }
    return 0;
}
