#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool Inside(int r, int c, int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void Traverse(vector<vector<int>>& st, vector<vector<vector<ii>>>& neigh, int r, int c, int col, int a, int b) {
    if (!Inside(r, c, st.size()) || st[r][c] == col)
        return;
    assert(st[r][c] == 0);
    st[r][c] = col;
    for (int i = -1; i <= 1; i += 2)
        for (int j = -1; j <= 1; j += 2) {
            ii fir = {r + i * a, c + j * b};
            if (Inside(fir.first, fir.second, st.size())) {
                neigh[r][c].push_back(fir);
                neigh[fir.first][fir.second].emplace_back(r, c);
                Traverse(st, neigh, fir.first, fir.second, -col, a, b);
            }
            fir = {r + i * b, c + j * a};
            if (Inside(fir.first, fir.second, st.size())) {
                neigh[r][c].push_back(fir);
                neigh[fir.first][fir.second].emplace_back(r, c);
                Traverse(st, neigh, fir.first, fir.second, -col, a, b);
            }
        }
}

const int MAXN = 300 * 300 + 5;
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

int getId(int r, int c, int n) { return r * n + c + 1; }

ii fromId(int v, int n) {
    v--;
    return {v / n, v % n};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector st(n, vector(n, 0));
    vector neigh(n, vector(n, vector<ii>()));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (st[i][j] == 0)
                Traverse(st, neigh, i, j, -1, a, b);
    vector<string> B(n);
    for (auto& x : B)
        cin >> x;
    N = 2 + n * n;
    s = 0, t = N - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (st[i][j] == -1) {
                add_edge(s, getId(i, j, n), B[i][j] != '#');
                for (auto& p : neigh[i][j])
                    add_edge(getId(i, j, n), getId(p.first, p.second, n), INF);
            } else add_edge(getId(i, j, n), t, B[i][j] != '#');
    dinic();
    vector rneigh(N, vector<int>());
    for (int i = 0; i < e.size(); i++)
        if (e[i].flow < e[i].cap)
            rneigh[e[i].a].push_back(e[i].b);
    vector marked(N, false);
    queue<int> Q;
    Q.push(s);
    marked[s] = true;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto u : rneigh[v])
            if (!marked[u]) {
                marked[u] = true;
                Q.push(u);
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (B[i][j] == '.')
                B[i][j] = 'o';
    for (int i = 0; i < e.size(); i++)
        if (marked[e[i].a] && !marked[e[i].b]) {
            if (e[i].a == s) {
                ii v = fromId(e[i].b, n);
                if (B[v.first][v.second] != '#')
                    B[v.first][v.second] = '.';
            } else if (e[i].b == t) {
                ii v = fromId(e[i].a, n);
                if (B[v.first][v.second] != '#')
                    B[v.first][v.second] = '.';
            }
        }
    for (auto& x : B)
        cout << x << "\n";
    return 0;
}
