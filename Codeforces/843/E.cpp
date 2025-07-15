#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;
const int MAXM = 2005;
const int INF = 1000000000;

struct edge {
	int a, b, cap, flow;
	int ind;
};

int N, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
bool mark[MAXN];
bool res[MAXM];
int A[MAXM], B[MAXM], wasg[MAXM];
int ans[MAXM];
int tres;

void add_edge (int a, int b, int cap, int ind) {
	edge e1 = { a, b, cap, 0, ind};
	edge e2 = { b, a, 0, 0, ind};
	if (cap == 1) e2.cap = INF;
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

void add_edge_once(int a, int b, int cap, int ind) {
	edge e1 = { a, b, cap, 0, ind};
	g[a].push_back ((int) e.size());
	e.push_back (e1);
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

void Mark(int v)
{
    if (mark[v]) return;
    mark[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int id = g[v][i];
        if (e[id].flow < e[id].cap)
            Mark(e[id].b);
    }
}

bool Reach(int a, int b)
{
    if (a == b) return true;
    if (mark[a]) return false;
    mark[a] = true;
    for (int i = 0; i < g[a].size(); i++) {
        int id = g[a][i];
        if (Reach(e[id].b, b)) {
            e[id].flow++;
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    N = n + 1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &A[i], &B[i], &wasg[i]);
        add_edge(A[i], B[i], wasg[i] == 0? INF: 1, i);
    }
    int dres = dinic();
    printf("%d\n", dres);
    Mark(s);
    for (int i = 0; i < e.size(); i++)
        if (mark[e[i].a] && !mark[e[i].b] && A[e[i].ind] == e[i].a) {
            res[e[i].ind] = true;
            tres++;
        }
    assert(dres == tres);
    for (int i = 0; i < N; i++)
        g[i].clear();
    e.clear();
    for (int i = 0; i < m; i++)
        if (wasg[i])
            add_edge_once(A[i], B[i], INF, i);
    for (int i = 0; i < e.size(); i++)
        if (e[i].flow == 0) {
            fill(mark, mark + N, false);
            Reach(s, e[i].a);
            fill(mark, mark + N, false);
            Reach(e[i].b, t);
            e[i].flow++;
        }
    for (int i = 0; i < e.size(); i++)
        ans[e[i].ind] += e[i].flow;
    for (int i = 0; i < m; i++) {
        assert((ans[i] > 0) == (wasg[i] > 0));
        int f = ans[i];
        int r = res[i]? ans[i]: ans[i] + 1;
        printf("%d %d\n", f, r);
    }
    return 0;
}