#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct edge {
    int a, b;
    bool taken;
    bool diff;
};

void Traverse(int v, vector<vector<ii>>& neigh, vector<edge>& E) {
    while (!neigh[v].empty()) {
        int e = neigh[v].back().second;
        int u = neigh[v].back().first;
        neigh[v].pop_back();
        if (E[e].taken)
            continue;
        E[e].taken = true;
        E[e].diff = E[e].a == v;
        Traverse(u, neigh, E);
    }
}

void Solve(vector<vector<ii>>& neigh, vector<edge>& E) {
    for (int i = 1; i < neigh.size(); i++)
        if (neigh[i].size() % 2) {
            cout << "-1\n";
            return;
        }
    for (int i = 1; i < neigh.size(); i++)
        if (!neigh[i].empty())
            Traverse(i, neigh, E);
    vector<int> res;
    for (int i = 0; i < E.size(); i++)
        if (E[i].diff)
            res.push_back(i);
    cout << res.size() << "\n";
    bool pr = false;
    for (auto x : res) {
        if (pr)
            cout << " ";
        else pr = true;
        cout << x + 1;
    }
    cout << "\n";
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
        vector<vector<ii>> neigh(n + 1);
        vector<edge> E;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            neigh[a[i]].emplace_back(b[i], i);
            neigh[b[i]].emplace_back(a[i], i);
            E.emplace_back(a[i], b[i], false);
        }
        Solve(neigh, E);
    }
    return 0;
}
