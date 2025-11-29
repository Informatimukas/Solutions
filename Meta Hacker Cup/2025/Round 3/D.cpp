#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxk = 20;

struct node {
    vector<int> neigh;
    int L{0};
    array<int, Maxk> P{};
    int lef, rig;
    vector<int> tneigh;
};

void Traverse(vector<node>& nodes, int v, int& cur) {
    nodes[v].lef = ++cur;
    for (auto& u : nodes[v].neigh) {
        if (u == nodes[v].P[0])
            continue;
        nodes[u].P[0] = v;
        nodes[u].L = nodes[v].L + 1;
        Traverse(nodes, u, cur);
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

int solveMiniTree(const vector<node>& nodes, int v, int d, int tot, ll& res) {
    int cnt = v % d == 0;
    for (auto& u : nodes[v].tneigh) {
        int got = solveMiniTree(nodes, u, d, tot, res);
        res += static_cast<ll>(nodes[u].L - nodes[v].L) * got * (tot - got);
        cnt += got;
    }
    return cnt;
}

ll Solve(vector<node>& nodes, int d, int n) {
    auto byLef = [&](int a, int b) { return nodes[a].lef < nodes[b].lef; };
    vector<int> seq;
    for (int i = d; i <= n; i += d)
        seq.push_back(i);
    ranges::sort(seq, byLef);
    int lim = seq.size();
    for (int i = 0; i + 1 < lim; i++) {
        int lca = getLCA(nodes, seq[i], seq[i + 1]);
        seq.push_back(lca);
    }
    ranges::sort(seq, byLef);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    vector<int> S;
    for (auto& v : seq) {
        nodes[v].tneigh.clear();
        while (!S.empty() && nodes[S.back()].rig < nodes[v].lef)
            S.pop_back();
        if (!S.empty())
            nodes[S.back()].tneigh.push_back(v);
        S.push_back(v);
    }
    ll res = 0;
    solveMiniTree(nodes, seq[0], d, n / d, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ":";
        int n;
        cin >> n;
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        int cur = 0;
        Traverse(nodes, 1, cur);
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                nodes[i].P[j] = nodes[nodes[i].P[j - 1]].P[j - 1];
        vector res(n + 1, 0ll);
        for (int i = n; i > 0; i--) {
            res[i] = Solve(nodes, i, n);
            for (int j = i + i; j <= n; j += i)
                res[i] -= res[j];
        }
        for (int i = 1; i <= n; i++)
            cout << " " << res[i];
        cout << "\n";
    }
    return 0;
}
