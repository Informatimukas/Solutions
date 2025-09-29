#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    int low{0}, tim{0};
    bool onStack{false};
    vector<int> neigh;
    int comp{0};
};

void SCC(int v, vector<node>& nodes, vector<int>& roots) {
    static int cur = 0;
    static int curcomp = 0;
    static vector<int> S;
    nodes[v].low = nodes[v].tim = ++cur;
    S.push_back(v);
    nodes[v].onStack = true;
    for (auto& u : nodes[v].neigh)
        if (!nodes[u].tim) {
            SCC(u, nodes, roots);
            nodes[v].low = min(nodes[v].low, nodes[u].low);
        } else if (nodes[u].onStack)
            nodes[v].low = min(nodes[v].low, nodes[u].tim);
    if (nodes[v].low == nodes[v].tim) {
        curcomp++;
        int w;
        do {
            w = S.back();
            S.pop_back();
            nodes[w].onStack = false;
            nodes[w].comp = curcomp;
        } while (w != v);
        roots.push_back(v);
    }
}

ll Solve(int v, ll k, const vector<node>& nodes) {
    map<int, int> M = {{v, 0}};
    vector seq = {v};
    int cyc = 0;
    for (int i = 0; i < seq.size(); i++) {
        v = seq[i];
        for (auto& u : nodes[v].neigh)
            if (nodes[v].comp == nodes[u].comp)
                if (M.contains(u))
                    cyc = __gcd(cyc, M[v] + 1 - M[u]);
                else {
                    M.emplace(u, M[v] + 1);
                    seq.push_back(u);
                }
    }
    if (cyc == 0)
        return 0;
    vector cnt(cyc, 0);
    for (auto& val : M | views::values)
        cnt[val % cyc]++;
    ll res = 0;
    if (k % cyc == 0) {
        res = seq.size();
        for (auto& c : cnt)
            res += static_cast<ll>(c) * (c - 1) / 2;
    }
    if (cyc % 2 == 0 && (k - cyc / 2) % cyc == 0)
        for (int i = 0; i < cyc / 2; i++)
            res += static_cast<ll>(cnt[i]) * cnt[i + cyc / 2];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<node> nodes(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].neigh.push_back(b);
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++)
        if (!nodes[i].tim)
            SCC(i, nodes, roots);
    ll res = 0;
    for (auto& v : roots)
        res += Solve(v, k, nodes);
    cout << res << "\n";
    return 0;
}
