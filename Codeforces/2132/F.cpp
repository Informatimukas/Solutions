#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<ii, int>;

constexpr int Inf = 1000000000;

struct edge {
    int a, b;
    bool bridge;
};

struct node {
    vector<ii> neigh;
    int low, tim;
    ii dist;
    node(): low{0}, tim{0}, dist{Inf, -2} {}
};

void Traverse(int v, int p, vector<node>& nodes, vector<edge>& edges) {
    static int tim = 0;
    nodes[v].tim = nodes[v].low = ++tim;
    for (auto& [u, ind]: nodes[v].neigh) {
        if (u == p) continue;
        if (nodes[u].tim)
            nodes[v].low = min(nodes[v].low, nodes[u].tim);
        else {
            Traverse(u, v, nodes, edges);
            nodes[v].low = min(nodes[v].low, nodes[u].low);
            if (nodes[v].tim < nodes[u].low)
                edges[ind].bridge = true;
        }
    }
}

vector<int> BFS(int v, const vector<node>& nodes) {
    vector dist(nodes.size(), numeric_limits<int>::max());
    dist[v] = 0;
    queue<int> Q;
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (auto& u : nodes[v].neigh | views::keys) {
            if (dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                Q.push(u);
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<node> nodes(n + 1);
        vector<edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].a >> edges[i].b;
            nodes[edges[i].a].neigh.emplace_back(edges[i].b, i);
            nodes[edges[i].b].neigh.emplace_back(edges[i].a, i);
            edges[i].bridge = false;
        }
        Traverse(1, 0, nodes, edges);
        auto dist1 = BFS(1, nodes);
        auto distn = BFS(n, nodes);
        bool wasBridge = false;
        priority_queue<iii, vector<iii>, greater<>> Q;
        for (int i = 0; i < m; i++) {
            if (edges[i].bridge && dist1[n] != dist1[edges[i].a] + distn[edges[i].b] + 1 &&
                dist1[n] != dist1[edges[i].b] + distn[edges[i].a] + 1)
                edges[i].bridge = false;
            if (edges[i].bridge) {
                wasBridge = true;
                if (ii{0, i} < nodes[edges[i].a].dist) {
                    nodes[edges[i].a].dist = {0, i};
                    Q.emplace(nodes[edges[i].a].dist, edges[i].a);
                }
                if (ii{0, i} < nodes[edges[i].b].dist) {
                    nodes[edges[i].b].dist = {0, i};
                    Q.emplace(nodes[edges[i].b].dist, edges[i].b);
                }
            }
        }
        int q;
        cin >> q;
        vector<int> queries(q);
        for (auto& x : queries)
            cin >> x;
        if (!wasBridge) {
            cout << "-1\n";
            continue;
        }
        while (!Q.empty()) {
            auto d = Q.top().first;
            int v = Q.top().second;
            Q.pop();
            if (nodes[v].dist != d) continue;
            ii cand = {d.first + 1, d.second};
            for (auto& u : nodes[v].neigh | views::keys)
                if (cand < nodes[u].dist) {
                    nodes[u].dist = cand;
                    Q.emplace(nodes[u].dist, u);
                }
        }
        for (int i = 0; i < queries.size(); i++) {
            cout << nodes[queries[i]].dist.second + 1 << (i + 1 < queries.size()? ' ': '\n');
        }
    }
    return 0;
}