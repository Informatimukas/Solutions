#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

struct node {
    vector<int> neigh;
    int L;
    bool onStack;
    array<ii, 2> best;
    bool interesting;
};

void addBest(array<ii, 2>& best, ii val) {
    if (val < best[0])
        best[1] = best[0], best[0] = val;
    else if (val < best[1])
        best[1] = val;
}

bool isInteresting(vector<node>& nodes, int v) {
    nodes[v].onStack = true;
    for (auto& u : nodes[v].neigh)
        if (!nodes[u].L) {
            nodes[u].L = nodes[v].L + 1;
            if (!isInteresting(nodes, u))
                return false;
        } else if (!nodes[u].onStack)
            return false;
    nodes[v].onStack = false;
    return true;
}

void computeBest(vector<node>& nodes, int v) {
    nodes[v].best = {ii{Inf, 0}, ii{Inf, 0}};
    for (auto& u : nodes[v].neigh)
        if (nodes[v].L + 1 == nodes[u].L) {
            computeBest(nodes, u);
            for (auto& p : nodes[u].best)
                addBest(nodes[v].best, p);
        } else addBest(nodes[v].best, {nodes[u].L, u});
}

void markInteresting(vector<node>& nodes, int v) {
    int st = 0;
    for (auto& [lvl, u] : nodes[v].best)
        if (lvl < nodes[v].L)
            st += nodes[u].interesting ? 1 : 2;
    nodes[v].interesting = st <= 1;
    for (auto& u : nodes[v].neigh)
        if (nodes[v].L + 1 == nodes[u].L)
            markInteresting(nodes, u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<node> nodes(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
        }
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        int root = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 1; j <= n; j++)
                nodes[j].L = 0;
            int v = uniform_int_distribution(1, n)(rng);
            nodes[v].L = 1;
            if (isInteresting(nodes, v)) {
                root = v;
                break;
            }
        }
        if (!root) {
            cout << "-1\n";
            continue;
        }
        computeBest(nodes, root);
        markInteresting(nodes, root);
        vector<int> res;
        for (int i = 1; i <= n; i++)
            if (nodes[i].interesting)
                res.push_back(i);
        if (5 * res.size() < n) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
