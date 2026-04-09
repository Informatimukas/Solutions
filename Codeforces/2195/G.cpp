#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxk = 20;

struct node {
    int ind, siz, par{0};
    ll sum{0};
    array<int, 2> neigh;
};

void Traverse(vector<node>& nodes, int v, vector<int>& seq) {
    nodes[v].ind = seq.size();
    seq.push_back(v);
    nodes[v].siz = 1;
    for (int u : nodes[v].neigh) {
        if (!u)
            continue;
        nodes[u].par = v;
        Traverse(nodes, u, seq);
        nodes[v].siz += nodes[u].siz + 1;
        seq.push_back(v);
    }
}

void countSum(vector<node>& nodes, int v) {
    nodes[v].sum += nodes[v].siz;
    for (auto u : nodes[v].neigh) {
        if (!u)
            continue;
        nodes[u].sum += nodes[v].sum;
        countSum(nodes, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<node> nodes(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].neigh[0] >> nodes[i].neigh[1];
        vector<int> seq;
        Traverse(nodes, 1, seq);
        vector P(n + 1, vector<int>(Maxk));
        for (int i = 1; i <= n; i++)
            P[i][0] = nodes[i].par;
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                P[i][j] = P[P[i][j - 1]][j - 1];
        countSum(nodes, 1);
        while (q--) {
            int v, k;
            cin >> v >> k;
            for (int i = Maxk - 1; i >= 0; i--) {
                int u = P[v][i];
                if (nodes[v].sum - nodes[u].sum <= k) {
                    k -= (nodes[v].sum - nodes[u].sum);
                    v = u;
                }
            }
            cout << seq[nodes[v].ind + k] << (q ? ' ' : '\n');
        }
    }
    return 0;
}
