#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

struct node {
    vector<int> neigh;
    bool col{false};
};

void Traverse(int v, int p, vector<node>& nodes, vector<int>& res) {
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        nodes[u].col = !nodes[v].col;
        Traverse(u, v, nodes, res);
    }
    res.push_back(v);
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
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        vector<int> seq;
        Traverse(n, 0, nodes, seq);
        bool cur = nodes[1].col;
        vector<ii> res;
        for (auto v : seq) {
            if (v == n)
                break;
            if (cur == nodes[v].col) {
                res.emplace_back(1, 0);
                cur = !cur;
            } else {
                res.emplace_back(1, 0);
                res.emplace_back(1, 0);
            }
            res.emplace_back(2, v);
        }
        cout << res.size() << "\n";
        for (auto& [fir, sec] : res) {
            cout << fir;
            if (fir > 1)
                cout << " " << sec;
            cout << "\n";
        }
    }
    return 0;
}
