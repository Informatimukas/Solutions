#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

struct node {
    vector<int> neigh;
    bool has{false};
    int col{-1}, d;
};

int getDist(int root, vector<node>& nodes) {
    int v = root;
    nodes[v].col = v;
    nodes[v].d = 0;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (auto u : nodes[v].neigh) {
            if (nodes[u].col != root) {
                nodes[u].col = root;
                if (nodes[u].has) {
                    nodes[root].has = true;
                    return nodes[v].d + 1;
                }
                nodes[u].d = nodes[v].d + 1;
                Q.push(u);
            }
        }
    }

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
        int c0;
        cin >> c0;
        nodes[c0].has = true;
        int res = Inf;
        vector<int> a(n);
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        for (int i = 1; i < n; i++) {
            res = min(res, getDist(a[i], nodes));
            cout << res << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
