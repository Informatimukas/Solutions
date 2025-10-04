#include <bits/stdc++.h>
using namespace std;

struct node {
    int low{0}, tim{0};
    vector<int> neigh;
    int comp;
    bool onStack{false};
    void addNode(int v) {
        if (v)
            neigh.push_back(v);
    }
};

int SCC(int v, vector<node>& nodes) {
    static int cur = 0;
    static int comp = 0;
    static vector<int> S;
    nodes[v].tim = nodes[v].low = ++cur;
    S.push_back(v);
    nodes[v].onStack = true;
    for (auto& u : nodes[v].neigh)
        if (!nodes[u].tim) {
            SCC(u, nodes);
            nodes[v].low = min(nodes[v].low, nodes[u].low);
        } else if (nodes[u].onStack)
            nodes[v].low = min(nodes[v].low, nodes[u].tim);
    if (nodes[v].tim == nodes[v].low) {
        comp++;
        int w;
        do {
            w = S.back();
            S.pop_back();
            nodes[w].onStack = false;
            nodes[w].comp = comp;
        } while (w != v);
    }
    return comp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    vector<int> need(m);
    for (auto& x : need)
        cin >> x;
    int N = 0;
    vector id(n, vector(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (B[i][j] == '#')
                id[i][j] = ++N;
    vector<node> nodes(N + 1);
    for (int j = 0; j < m; j++) {
        int lef = 0, mid = 0, rig = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (j && id[i][j - 1])
                lef = id[i][j - 1];
            if (j + 1 < m && id[i][j + 1])
                rig = id[i][j + 1];
            if (id[i][j]) {
                nodes[id[i][j]].addNode(lef);
                nodes[id[i][j]].addNode(mid);
                nodes[id[i][j]].addNode(rig);
                if (i)
                    nodes[id[i][j]].addNode(id[i - 1][j]);
                mid = id[i][j];
            }
        }
    }
    int comp = 0;
    for (int i = 1; i <= N; i++)
        if (!nodes[i].tim)
            comp = SCC(i, nodes);
    vector<int> res(comp + 1);
    vector<int> lef(m), rig(m), nxt(m, 0);
    for (int j = 0; j < m; j++) {
        vector best(n, m);
        int curBest = m;
        if (j)
            for (int i = n - 1; i >= 0; i--) {
                if (id[i][j - 1])
                    curBest = res[nodes[id[i][j - 1]].comp];
                best[i] = curBest;
            }
        int cnt = 0;
        lef[j] = j;
        for (int i = n - 1; i >= 0; i--)
            if (id[i][j]) {
                cnt++;
                res[nodes[id[i][j]].comp] = cnt >= need[j] ? min(j, best[i]) : m;
                lef[j] = res[nodes[id[i][j]].comp];
            }
    }
    for (int j = m - 1; j >= 0; j--) {
        vector best(n, -1);
        int curBest = -1;
        if (j + 1 < m)
            for (int i = n - 1; i >= 0; i--) {
                if (id[i][j + 1])
                    curBest = res[nodes[id[i][j + 1]].comp];
                best[i] = curBest;
            }
        int cnt = 0;
        rig[j] = j;
        for (int i = n - 1; i >= 0; i--)
            if (id[i][j]) {
                cnt++;
                res[nodes[id[i][j]].comp] = cnt >= need[j] ? max(j, best[i]) : -1;
                rig[j] = res[nodes[id[i][j]].comp];
            }
        nxt[lef[j]] = max(nxt[lef[j]], rig[j] + 1);
    }
    int ans = 0;
    for (int j = 1; j < m; j++)
        nxt[j] = max(nxt[j], nxt[j - 1]);
    int cur = 0;
    while (cur < m)
        if (need[cur] == 0) cur++;
        else {
            ans++;
            cur = nxt[cur];
        }
    cout << ans << "\n";
    return 0;
}