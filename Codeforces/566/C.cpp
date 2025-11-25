#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ld = long double;
using ldi = pair<ld, int>;
using ldld = pair<ld, ld>;

struct node {
    int w;
    vector<ii> neigh;
    bool er{false};
    int cnt;
};

void Count(vector<node>& nodes, int v, int p) {
    nodes[v].cnt = 1;
    for (auto& u : nodes[v].neigh | views::keys) {
        if (u == p || nodes[u].er)
            continue;
        Count(nodes, u, v);
        nodes[v].cnt += nodes[u].cnt;
    }
}

int getCentroid(vector<node>& nodes, int v, int p, int need) {
    for (auto& u : nodes[v].neigh | views::keys) {
        if (u == p || nodes[u].er)
            continue;
        if (nodes[u].cnt > need)
            return getCentroid(nodes, u, v, need);
    }
    return v;
}

ldld Traverse(const vector<node>& nodes, int v, int p, int dist) {
    ld sroot = sqrt(static_cast<ld>(dist));
    ld res1 = sroot * dist * nodes[v].w;
    ld res2 = sroot * nodes[v].w;
    for (auto& [u, d] : nodes[v].neigh) {
        if (u == p)
            continue;
        auto got = Traverse(nodes, u, v, dist + d);
        res1 += got.first;
        res2 += got.second;
    }
    return {res1, res2};
}

ldi Solve(vector<node>& nodes, int v) {
    Count(nodes, v, 0);
    int C = getCentroid(nodes, v, 0, nodes[v].cnt / 2);
    ld cand = 0;
    ld mx = -1;
    int wth = -1;
    for (auto& [u, d] : nodes[C].neigh) {
        auto got = Traverse(nodes, u, C, d);
        cand += got.first;
        if (got.second > mx) {
            mx = got.second;
            wth = u;
        }
    }
    ldi res = {cand, C};
    nodes[C].er = true;
    if (wth != -1 && !nodes[wth].er)
        res = min(res, Solve(nodes, wth));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nodes[i].w;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].neigh.emplace_back(b, c);
        nodes[b].neigh.emplace_back(a, c);
    }
    auto res = Solve(nodes, 1);
    cout << res.second << " " << fixed << setprecision(10) << res.first << "\n";
    return 0;
}