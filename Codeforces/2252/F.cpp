#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Maxk = 20;

struct node {
    int c{0};
    vector<int> neigh;
    vector<int> P;
    int L{0}, lef{0}, rig{0}, car{0};
    node(): P(Maxk) {}
};

void Traverse(vector<node>& nodes, int v, int& cur) {
    nodes[v].lef = ++cur;
    for (auto u : nodes[v].neigh) {
        if (nodes[v].P[0] == u)
            continue;
        nodes[u].L = nodes[v].L + 1;
        nodes[u].P[0] = v;
        Traverse(nodes, u, cur);
    }
    nodes[v].rig = cur;
}

int getLCA(const vector<node>& nodes, int a, int b) {
    if (nodes[a].L < nodes[b].L)
        swap(a, b);
    for (int j = Maxk - 1; j >= 0; j--)
        if (nodes[a].L - (1 << j) >= nodes[b].L)
            a = nodes[a].P[j];
    if (a == b)
        return a;
    for (int j = Maxk - 1; j >= 0; j--)
        if (nodes[a].P[j] != nodes[b].P[j])
            a = nodes[a].P[j], b = nodes[b].P[j];
    return nodes[a].P[0];
}

ll Solve(vector<node>& nodes, int mycol, vector<int> seq, int k) {
    int seqsiz = seq.size();
    if (seq.empty())
        return -1;
    auto bylef = [&](auto&& x) { return nodes[x].lef; };
    ranges::sort(seq, {}, bylef);
    int lim = seq.size();
    for (int i = 0; i + 1 < lim; i++)
        seq.push_back(getLCA(nodes, seq[i], seq[i + 1]));
    ranges::sort(seq, {}, bylef);
    seq.erase(ranges::unique(seq).begin(), seq.end());
    int totcnt = 1;
    vector<ii> srt;
    vector<int> S;
    for (auto v : seq) {
        nodes[v].car = nodes[v].c == mycol;
        while (!S.empty() && nodes[S.back()].rig < nodes[v].lef) {
            int b = S.back();
            S.pop_back();
            int a = S.back();
            nodes[a].car += nodes[b].car;
            int val = min(nodes[b].car, seqsiz - nodes[b].car);
            totcnt += nodes[b].L - nodes[a].L;
            srt.emplace_back(val, nodes[b].L - nodes[a].L);
        }
        S.push_back(v);
    }
    while (!S.empty()) {
        int b = S.back();
        S.pop_back();
        if (S.empty())
            break;
        int a = S.back();
        nodes[a].car += nodes[b].car;
        int val = min(nodes[b].car, seqsiz - nodes[b].car);
        totcnt += nodes[b].L - nodes[a].L;
        srt.emplace_back(val, nodes[b].L - nodes[a].L);
    }
    ranges::sort(srt);
    k = totcnt - k;
    ll totw = 0;
    for (auto& [value, cnt] : srt) {
        int tk = min(cnt, k);
        k -= tk;
        totw += static_cast<ll>(tk) * value;
    }
    return totw;
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
        vector<vector<int>> bycol(n + 1);
        vector<int> k(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> nodes[i].c;
            bycol[nodes[i].c].push_back(i);
        }
        for (int i = 1; i <= n; i++)
            cin >> k[i];
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
        for (int i = 1; i <= n; i++)
            cout << Solve(nodes, i, bycol[i], k[i]) << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
