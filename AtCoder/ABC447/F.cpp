#include <bits/stdc++.h>
using namespace std;

int Traverse(const vector<vector<int>>& neigh, int v, int p, int& res) {
    vector<int> seq;
    for (auto u : neigh[v]) {
        if (u == p)
            continue;
        seq.push_back(Traverse(neigh, u, v, res));
    }
    ranges::sort(seq, greater());
    if (neigh[v].size() >= 4)
        res = max(res, 1 + seq[0] + seq[1]);
    if (neigh[v].size() >= 3)
        res = max(res, 1 + seq[0]);
    int cur = neigh[v].size() - (p != 0) >= 2 ? 1 : 0;
    if (neigh[v].size() - (p != 0) >= 3)
        cur = 1 + seq[0];
    return cur;
}

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
        int res = 1;
        Traverse(neigh, 1, 0, res);
        cout << res << "\n";
    }
    return 0;
}
