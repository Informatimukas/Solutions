#include <bits/stdc++.h>
using namespace std;

bool Get(int v, const vector<vector<int>>& neigh, const vector<int>& col, set<int>& res) {
    bool all = true;
    for (auto u : neigh[v]) {
        bool got = Get(u, neigh, col, res);
        all &= got;
    }
    if (col[v] == 1 && all)
        res.insert(v);
    return col[v] == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> neigh(n + 1);
    vector<int> col(n + 1);
    int root = 0;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> col[i];
        if (p == -1)
            root = i;
        else neigh[p].push_back(i);
    }
    set<int> res;
    for (auto u : neigh[root])
        Get(u, neigh, col, res);
    if (res.empty())
        cout << "-1\n";
    else {
        bool was = false;
        for (auto el : res) {
            if (was)
                cout << " ";
            else was = true;
            cout << el;
        }
        cout << "\n";
    }
    return 0;
}
