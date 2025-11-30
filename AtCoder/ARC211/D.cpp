#include <bits/stdc++.h>
using namespace std;

struct node {
    vector<int> neigh;
    map<int, bool> M;
    int from, to;
};

bool Solve(vector<node>& nodes, int v, int p) {
    auto it = nodes[v].M.find(p);
    if (it != nodes[v].M.end())
        return it->second;
    if (nodes[v].M.size() >= 2)
        return nodes[v].M.begin()->second || nodes[v].M.rbegin()->second;
    nodes[v].M.emplace(p, false);
    if (v == 2) {
        nodes[v].M[p] = true;
        return true;
    }
    bool got = false;
    for (auto& u : nodes[v].neigh) {
        if (u == p)
            continue;
        if (Solve(nodes, u, v)) {
            nodes[v].to = u;
            nodes[u].from = v;
            got = true;
        }
    }
    cout << "nodes[" << v << "][" << p << "] = " << got << endl;
    nodes[v].M[p] = got;
    return got;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<node> nodes(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].neigh.push_back(b);
        nodes[b].neigh.push_back(a);
    }
    bool got = Solve(nodes, 1, 0);
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (auto& x : nodes[i].M | views::values)
            ok |= x;
        if (!ok)
            got = false;
    }
    if (!got) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << nodes[1].to << "\n";
    cout << nodes[2].from << "\n";
    for (int i = 3; i <= n; i++)
        cout << nodes[i].from << " " << nodes[i].to << "\n";
    return 0;
}
