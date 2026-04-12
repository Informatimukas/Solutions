#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int mod = 998244353;

struct node {
    vector<int> neigh;
    int P{0}, L{0};
    int res{0};
};

void Traverse(vector<node>& nodes, int v, int p, vector<vector<int>>& bylevel) {
    bylevel[nodes[v].L].push_back(v);
    nodes[v].P = p;
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u, v, bylevel);
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
        string a;
        cin >> a;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        vector<vector<int>> bylevel(n);
        Traverse(nodes, 1, 0, bylevel);
        vector<ii> seq;
        seq.reserve(n * n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--)
                for (auto& a : bylevel[i])
                    for (auto& b : bylevel[j]) {
                        seq.emplace_back(a, b);
                        seq.emplace_back(b, a);
                    }
            for (auto& a : bylevel[i])
                for (auto& b : bylevel[i])
                    seq.emplace_back(a, b);
        }
        vector res(n + 1, vector(n + 1, array{0, 0, 0}));
        for (auto& [u, v] : seq) {
            res[nodes[u].P][v][0] = (res[nodes[u].P][v][0] + res[u][v][0]) % mod;
            res[u][v][1] = (res[u][v][1] + res[u][v][0]) % mod;
            if (a[u - 1] == a[v - 1]) {
                int ways = (res[u][v][1] + 1) % mod;
                res[u][v][2] = (res[u][v][2] + ways) % mod;
                res[nodes[u].P][nodes[v].P][0] = (res[nodes[u].P][nodes[v].P][0] + ways) % mod;
            }
            res[u][nodes[v].P][1] = (res[u][nodes[v].P][1] + res[u][v][1]) % mod;
            if (u == v)
                nodes[u].res = (nodes[u].res + res[u][v][2]) % mod;
            if (nodes[u].L >= nodes[v].L)
                res[nodes[u].P][v][2] = (res[nodes[u].P][v][2] + res[u][v][2]) % mod;
            else res[u][nodes[v].P][2] = (res[u][nodes[v].P][2] + res[u][v][2]) % mod;
        }
        for (int i = 1; i <= n; i++)
            cout << nodes[i].res << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
