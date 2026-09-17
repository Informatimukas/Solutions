#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Switch(int a, int b, vector<set<int>>& neigh, set<ii>& S) {
    S.erase({neigh[a].size(), a});
    S.erase({neigh[b].size(), b});
    if (neigh[a].contains(b)) {
        neigh[a].erase(b);
        neigh[b].erase(a);
    } else {
        neigh[a].insert(b);
        neigh[b].insert(a);
    }
    S.insert({neigh[a].size(), a});
    S.insert({neigh[b].size(), b});
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
        vector<set<int>> neigh(n + 1);
        set<ii> S;
        vector<array<int, 3>> res;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].insert(b);
            neigh[b].insert(a);
        }
        for (int i = 1; i <= n; i++)
            S.insert({neigh[i].size(), i});
        while (S.rbegin()->first >= 2) {
            int v = S.rbegin()->second;
            int a = *neigh[v].begin();
            int b = *next(neigh[v].begin());
            res.push_back({v, a, b});
            Switch(v, a, neigh, S);
            Switch(v, b, neigh, S);
            Switch(a, b, neigh, S);
        }
        if (S.rbegin()->first == 1) {
            int root = S.rbegin()->second;
            int e1 = root, e2 = *neigh[root].begin();
            set tk = {e1, e2};
            for (int i = 1; i <= n; i++)
                if (!tk.contains(i)) {
                    tk.insert(i);
                    if (!neigh[i].empty())
                        tk.insert(*neigh[i].begin());
                    res.push_back({e1, e2, i});
                    Switch(e1, e2, neigh, S);
                    Switch(e1, i, neigh, S);
                    Switch(e2, i, neigh, S);
                    e2 = i;
                }
        }
        cout << res.size() << "\n";
        for (auto& arr : res)
            cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    }
    return 0;
}
