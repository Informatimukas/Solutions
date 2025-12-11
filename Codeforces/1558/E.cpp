#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int lim = 1000000007;

struct node {
    int a{0}, b{0};
    int mema{0}, memb{0};
    bool joined{false};
    vector<ii> neigh;
};

int toUp(vector<node>& nodes, int v, const vector<int>& par, ll& cur) {
    if (nodes[v].joined)
        return 0;
    nodes[v].joined = true;
    cur += nodes[v].b;
    return toUp(nodes, par[v], par, cur) + 1;
}

int Added(vector<node>& nodes, const vector<ii>& edges, ll& cur) {
    for (int i = 1; i < nodes.size(); i++)
        nodes[i].neigh.clear();
    vector<ii> E;
    for (auto& [a, b] : edges) {
        int v = nodes[a].joined ? 1 : a;
        int u = nodes[b].joined ? 1 : b;
        if (v != u) {
            nodes[v].neigh.emplace_back(u, E.size());
            nodes[u].neigh.emplace_back(v, E.size());
            E.emplace_back(u, v);
        }
    }
    vector taken(nodes.size(), false);
    vector mx(nodes.size(), 0ll);
    vector<int> par(nodes.size());
    mx[1] = cur;
    taken[1] = true;
    queue<ii> Q;
    Q.emplace(1, -1);
    int special = -1, wth = -1;
    while (!Q.empty()) {
        auto [v, forb] = Q.front();
        Q.pop();
        ll my = mx[v] + nodes[v].b;
        bool stop = false;
        for (auto& [u, ind] : nodes[v].neigh)
            if (ind != forb && my > nodes[u].a) {
                if (taken[u]) {
                    special = u;
                    wth = v;
                    stop = true;
                    break;
                }
                mx[u] = my;
                taken[u] = true;
                par[u] = v;
                Q.emplace(u, ind);
            }
        if (stop)
            break;
    }
    if (special == -1)
        return 0;
    return toUp(nodes, special, par, cur) + toUp(nodes, wth, par, cur);
}

bool canSolve(vector<node>& nodes, const vector<ii>& edges, ll cur) {
    int n = nodes.size() - 1;
    for (int i = 1; i < nodes.size(); i++) {
        nodes[i].a = nodes[i].mema;
        nodes[i].b = nodes[i].memb;
        nodes[i].joined = false;
    }
    nodes[1].joined = true;
    int need = n - 1;
    while (need > 0) {
        int got = Added(nodes, edges, cur);
        if (!got)
            return false;
        need -= got;
    }
    return true;
}

ll Solve(vector<node>& nodes, const vector<ii>& edges) {
    ll lef = 0, rig = lim;
    while (lef <= rig) {
        ll mid = (lef + rig) / 2;
        if (canSolve(nodes, edges, mid))
            rig = mid - 1;
        else lef = mid + 1;
    }
    return lef;
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
        for (int i = 2; i <= n; i++)
            cin >> nodes[i].a;
        for (int i = 2; i <= n; i++) {
            cin >> nodes[i].b;
            nodes[i].mema = nodes[i].a;
            nodes[i].memb = nodes[i].b;
        }
        vector<ii> edges(m);
        for (auto& [a, b] : edges)
            cin >> a >> b;
        cout << Solve(nodes, edges) << "\n";
    }
    return 0;
}