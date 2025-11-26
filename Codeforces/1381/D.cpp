#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxk = 20;
constexpr int Maxb = 3;

struct node {
    vector<int> neigh;
    int L{0};
    array<int, Maxk> P{};
    array<int, Maxb> best{};
};

void addBest(array<int, Maxb>& arr, int value) {
    for (int i = 0; i < arr.size(); i++)
        if (value > arr[i]) {
            for (int j = arr.size() - 2; j >= i; j--)
                arr[j + 1] = arr[j];
            arr[i] = value;
            break;
        }
}

int getBest(const array<int, Maxb>& arr, int value) {
    return arr[0] == value ? arr[1] : arr[0];
}

bool checkBest(const array<int, Maxb>& arr, int tp, int need) {
    return arr[0] >= need && arr[1] >= need && max(arr[2], tp) >= need;
}

void Traverse(vector<node>& nodes, int v) {
    for (auto& u : nodes[v].neigh) {
        if (u == nodes[v].P[0])
            continue;
        nodes[u].P[0] = v;
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u);
        addBest(nodes[v].best, nodes[u].best[0] + 1);
    }
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

int goUp(const vector<node>& nodes, int v, int steps) {
    for (int i = Maxk - 1; i >= 0; i--)
        if (1 << i <= steps) {
            v = nodes[v].P[i];
            steps -= 1 << i;
        }
    return v;
}

int Move(const vector<node>& nodes, int from, int to, int steps) {
    int lca = getLCA(nodes, from, to);
    int d1 = nodes[from].L - nodes[lca].L;
    if (steps <= d1)
        return goUp(nodes, from, steps);
    steps -= d1;
    return goUp(nodes, to, nodes[to].L - nodes[lca].L - steps);
}

bool traverseCheck(const vector<node>& nodes, int v, int tp, int need) {
    if (checkBest(nodes[v].best, tp, need))
        return true;
    return ranges::any_of(nodes[v].neigh, [&](int u) {
        if (u == nodes[v].P[0])
            return false;
        int ntp = max(tp, getBest(nodes[v].best, nodes[u].best[0] + 1)) + 1;
        return traverseCheck(nodes, u, ntp, need);
    });
}

ii Get(map<ii, ii>& M, const vector<node>& nodes, const ii& key) {
    auto it = M.find(key);
    if (it != M.end())
        return it->second;
    ii res = {0, key.first};
    for (auto& u : nodes[key.first].neigh) {
        if (u == key.second)
            continue;
        ii got = Get(M, nodes, {u, key.first});
        res = max(res, {got.first + 1, got.second});
    }
    M.insert({key, res});
    return res;
}

bool Solve(const vector<node>& nodes, int a, int b, int dist) {
    map<ii, ii> M;
    while (true) {
        int nxt = Move(nodes, b, a, dist - 1);
        ii key = {a, nxt};
        if (M.contains(key))
            return false;
        ii got = Get(M, nodes, key);
        if (got.first >= dist)
            return true;
        int nb = got.second;
        int na = Move(nodes, b, a, got.first);
        a = na;
        b = nb;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            nodes[u].neigh.push_back(v);
            nodes[v].neigh.push_back(u);
        }
        Traverse(nodes, 1);
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                nodes[i].P[j] = nodes[nodes[i].P[j - 1]].P[j - 1];
        int dist = getDist(nodes, a, b);
        if (!traverseCheck(nodes, 1, 0, dist)) {
            cout << "NO\n";
            continue;
        }
        cout << (Solve(nodes, a, b, dist) ? "YES" : "NO") << "\n";
    }
    return 0;
}