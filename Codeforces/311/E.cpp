#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int INF = 1000000000;

struct edge {
    int a, b, cap, flow;
};

int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, N * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, N * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, fpen;
    cin >> n >> m >> fpen;
    N = n + m + 2;
    s = 0, t = N - 1;
    vector<int> gender(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> gender[i];
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        add_edge(s, i, gender[i] == 1 ? 0 : v);
        add_edge(i, t, gender[i] == 0 ? 0 : v);
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int sex, w, k;
        cin >> sex >> w >> k;
        res += w;
        vector<int> dogs(k);
        for (auto& x : dogs)
            cin >> x;
        int fr;
        cin >> fr;
        int pen = w + (fr ? fpen : 0);
        if (sex == 0) {
            add_edge(s, n + i, pen);
            for (auto x : dogs)
                add_edge(n + i, x, INF);
        } else {
            add_edge(n + i, t, pen);
            for (auto x : dogs)
                add_edge(x, n + i, INF);
        }
    }
    res -= dinic();
    cout << res << "\n";
    return 0;
}
