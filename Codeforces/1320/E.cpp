#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;
using ii = pair<int, int>;
using llii = pair<lli, int>;

constexpr int Maxk = 20;
constexpr ll Inf = 4000000000000000000ll;

struct node {
    vector<int> neigh;
    array<int, Maxk> P{};
    int L{0};
    int lef, rig;
    vector<int> tneigh;
    lli dist;
};

void Traverse(vector<node>& nodes, int v) {
    static int cur = 0;
    nodes[v].lef = ++cur;
    for (auto& u : nodes[v].neigh) {
        if (u == nodes[v].P[0])
            continue;
        nodes[u].P[0] = v;
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u);
    }
    nodes[v].rig = cur;
}

int getLCA(const vector<node>& nodes, int a, int b) {
    if (nodes[a].L < nodes[b].L)
        swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[a].L - (1 << i) >= nodes[b].L)
            a = nodes[a].P[i];
    if (a == b)
        return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (nodes[a].P[i] != nodes[b].P[i])
            a = nodes[a].P[i], b = nodes[b].P[i];
    return nodes[a].P[0];
}

int getDist(const vector<node>& nodes, int a, int b) {
    int lca = getLCA(nodes, a, b);
    return nodes[a].L + nodes[b].L - 2 * nodes[lca].L;
}

vector<int> Solve(vector<node>& nodes, const vector<ii>& virus, const vector<int>& cities) {
    vector<int> seq = cities;
    for (auto& x : virus | views::keys)
        seq.push_back(x);
    auto byLef = [&](int v, int u) { return nodes[v].lef < nodes[u].lef; };
    ranges::sort(seq, byLef);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    int lim = seq.size();
    for (int i = 0; i + 1 < lim; i++)
        seq.push_back(getLCA(nodes, seq[i], seq[i + 1]));
    ranges::sort(seq, byLef);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    for (auto& x : seq) {
        nodes[x].dist = {Inf, -1};
        nodes[x].tneigh.clear();
    }
    stack<int> S;
    for (auto& x : seq) {
        while (!S.empty() && nodes[S.top()].rig < nodes[x].lef)
            S.pop();
        if (!S.empty()) {
            nodes[S.top()].tneigh.push_back(x);
            nodes[x].tneigh.push_back(S.top());
        }
        S.push(x);
    }
    priority_queue<llii, vector<llii>, greater<>> pq;
    for (int i = 0; i < virus.size(); i++) {
        int v = virus[i].first;
        nodes[v].dist = {0, i};
        pq.push({{0, i}, v});
    }
    while (!pq.empty()) {
        lli d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (nodes[v].dist != d)
            continue;
        int ind = d.second;
        for (auto& u : nodes[v].tneigh) {
            int steps = (getDist(nodes, virus[ind].first, u) + virus[ind].second - 1) /
                virus[ind].second;
            ll cand = static_cast<ll>(virus.size()) * (steps - 1) + ind;
            if (cand < nodes[u].dist.first) {
                nodes[u].dist = {cand, ind};
                pq.emplace(nodes[u].dist, u);
            }
        }
    }
    vector<int> res(cities.size());
    for (int i = 0; i < cities.size(); i++)
        res[i] = nodes[cities[i]].dist.second;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<node> nodes(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].neigh.push_back(y);
        nodes[y].neigh.push_back(x);
    }
    Traverse(nodes, 1);
    for (int j = 1; j < Maxk; j++)
        for (int i = 1; i <= n; i++)
            nodes[i].P[j] = nodes[nodes[i].P[j - 1]].P[j - 1];
    int q;
    cin >> q;
    while (q--) {
        int k, m;
        cin >> k >> m;
        vector<ii> virus(k);
        for (auto& [v, s] : virus)
            cin >> v >> s;
        vector<int> cities(m);
        for (auto& x : cities)
            cin >> x;
        auto res = Solve(nodes, virus, cities);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] + 1 << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}