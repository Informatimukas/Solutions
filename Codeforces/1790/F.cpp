#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

struct node {
    vector<int> neigh;
    int siz;
    vector<array<int, 3>> my;
    bool er{false};
    array<ii, 2> best{ii{Inf, Inf}, ii{Inf, Inf}};
};

void Count(int v, int p, vector<node>& nodes) {
    nodes[v].siz = 1;
    for (auto u : nodes[v].neigh) {
        if (u == p || nodes[u].er)
            continue;
        Count(u, v, nodes);
        nodes[v].siz += nodes[u].siz;
    }
}

int getCentroid(int v, int p, int lim, vector<node>& nodes) {
    for (auto u : nodes[v].neigh) {
        if (u == p || nodes[u].er)
            continue;
        if (nodes[u].siz > lim)
            return getCentroid(u, v, lim, nodes);
    }
    return v;
}

void Traverse(int v, int p, int d, const ii& val, vector<node>& nodes) {
    nodes[v].my.push_back({val.first, val.second, d});
    for (auto u : nodes[v].neigh) {
        if (u == p || nodes[u].er)
            continue;
        Traverse(u, v, d + 1, val, nodes);
    }
}

void getCentroids(int v, vector<node>& nodes) {
    Count(v, 0, nodes);
    int C = getCentroid(v, 0, nodes[v].siz / 2, nodes);
    for (int i = 0; i < nodes[C].neigh.size(); i++) {
        int u = nodes[C].neigh[i];
        if (nodes[u].er)
            continue;
        Traverse(u, C, 1, {C, i}, nodes);
    }
    nodes[C].my.push_back({C, static_cast<int>(nodes[C].neigh.size()), 0});
    nodes[C].er = true;
    for (auto u : nodes[C].neigh) {
        if (nodes[u].er)
            continue;
        getCentroids(u, nodes);
    }
}

void Update(array<ii, 2>& best, ii val) {
    if (best[0].second == val.second) {
        best[0].first = min(best[0].first, val.first);
        return;
    }
    if (best[1].second == val.second) {
        best[1].first = min(best[1].first, val.first);
        if (best[1] < best[0])
            swap(best[1], best[0]);
        return;
    }
    if (val < best[0]) {
        best[1] = best[0];
        best[0] = val;
    } else if (val < best[1])
        best[1] = val;
}

int Process(int v, vector<node>& nodes) {
    int res = Inf;
    for (auto& arr : nodes[v].my) {
        int C = arr[0], ind = arr[1], d = arr[2];
        Update(nodes[C].best, {d, ind});
        res = min(res, nodes[C].best[0].first + nodes[C].best[1].first);
    }
    return res;
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
        vector<int> a(n);
        for (int i = 1; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        getCentroids(1, nodes);
        Process(c0, nodes);
        int res = Inf;
        for (int i = 1; i < n; i++) {
            res = min(res, Process(a[i], nodes));
            cout << res << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
