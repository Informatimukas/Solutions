#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll val{0}, sum{0}, best{0}, level{0};
    ll a{0};
    vector<int> neigh;
};

void Traverse(int v, int p, vector<node>& nodes) {
    nodes[v].sum += nodes[v].a;
    ll L = 0, S = 0;
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        Traverse(u, v, nodes);
        nodes[v].sum += nodes[u].sum;
        nodes[v].val += nodes[u].val + nodes[u].sum;
        nodes[v].best = max(nodes[v].best, nodes[u].best);
        nodes[v].level = max(nodes[v].level, nodes[u].level + 1);
        nodes[v].best = max(nodes[v].best, S * (nodes[u].level + 1));
        nodes[v].best = max(nodes[v].best, L * nodes[u].sum);
        L = max(L, nodes[u].level + 1);
        S = max(S, nodes[u].sum);
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
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].a;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        Traverse(1, 0, nodes);
        for (int i = 1; i <= n; i++)
            cout << nodes[i].val + nodes[i].best << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
