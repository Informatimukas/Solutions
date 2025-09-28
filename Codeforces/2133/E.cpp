#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void Search(int v, vector<set<int>>& neigh, set<int>& tk, vector<ii>& res) {
    tk.insert(v);
    res.emplace_back(1, v);
    if (!neigh[v].empty()) {
        int u = *neigh[v].begin();
        neigh[v].erase(u);
        neigh[u].erase(v);
        Search(u, neigh, tk, res);
    }
}

bool Traverse(int v, int p, vector<set<int>>& neigh, vector<ii>& res) {
    bool bad = false;
    for (auto it = neigh[v].begin(); it != neigh[v].end(); ) {
        int u = *it;
        if (u == p) {
            ++it;
            continue;
        }
        if (Traverse(u, v, neigh, res)) {
            if (neigh[u].size() >= 3)
                bad = true;
            ++it;
        } else neigh[v].erase(it++);
    }
    if (bad || neigh[v].size() > 3) {
        res.emplace_back(2, v);
        for (auto& u : neigh[v]) {
            if (u == p)
                continue;
            neigh[u].erase(v);
        }
        neigh[v].clear();
        return false;
    }
    return true;
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
        vector neigh(n + 1, set<int>());
        set<int> tk;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].insert(b);
            neigh[b].insert(a);
        }
        int root = 1;
        while (neigh[root].size() > 1)
            root++;
        vector<ii> res;
        Traverse(root, 0, neigh, res);
        for (int i = 1; i <= n; i++)
            if (!tk.contains(i) && neigh[i].size() < 2)
                Search(i, neigh, tk, res);
        cout << res.size() << "\n";
        for (auto& [res1, res2] : res)
            cout << res1 << " " << res2 << "\n";
    }
    return 0;
}
