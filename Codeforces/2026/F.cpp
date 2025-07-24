#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 30005;
constexpr int Maxm = 2005;
constexpr int Maxk = 16;

int T;
int n, s;
ii endpoints[Maxn];
ii pt[Maxn];
int dp0[Maxn][Maxm], dp1[Maxn][Maxm], zer[Maxm];
int L[Maxn], P[Maxn][Maxk];
vector<int> neigh[Maxn];
int col[Maxn], cnt[Maxn];
bool rem[Maxn];
int A[Maxn], B[Maxn], V[Maxn];
int res[Maxn];
int rlen;

void addEdge(int v, int u) {
    neigh[v].push_back(u);
    neigh[u].push_back(v);
    L[u] = L[v] + 1;
    P[u][0] = v;
    for (int i = 1; i < Maxk; i++)
        P[u][i] = P[P[u][i - 1]][i - 1];
}

int getNext(int a, int b) {
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[b] - (1 << i) > L[a])
            b = P[b][i];
    return b;
}

void Count(int v, int p) {
    cnt[v] = 1;
    for (auto u : neigh[v]) {
        if (u == p || rem[u]) continue;
        Count(u, v);
        cnt[v] += cnt[u];
    }
}

int getCentroid(int v, int p, int nd) {
    for (auto u: neigh[v]) {
        if (p == u || rem[u]) continue;
        if (cnt[u] > nd)
            return getCentroid(u, v, nd);
    }
    return v;
}

void Colour(int v, int p, int c) {
    col[v] = c;
    for (auto u: neigh[v]) {
        if (p == u || rem[u]) continue;
        Colour(u, v, c);
    }
}

void Solve(int v, int p, int old[], int dp[][Maxm]) {
    for (int i = 0; i < pt[v].first; i++)
        dp[v][i] = old[i];
    for (int i = pt[v].first; i < Maxm; i++)
        dp[v][i] = max(old[i], old[i - pt[v].first] + pt[v].second);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (rem[u] || p == u) continue;
        Solve(u, v, dp[v], dp);
    }
}

void Solve(int v, const vector<int> &quer) {
    Count(v, 0);
    int C = getCentroid(v, 0, cnt[v] / 2);
    col[C] = -1;
    vector<vector<int>> nquer(neigh[C].size());
    for (int i = 0; i < neigh[C].size(); i++) {
        int v = neigh[C][i];
        if (rem[v]) continue;
        Colour(v, C, i);
    }
    vector<int> myquer;
    for (auto ind: quer)
        if (col[A[ind]] != col[B[ind]])
            myquer.push_back(ind);
        else nquer[col[A[ind]]].push_back(ind);
    if (!myquer.empty()) {
        Solve(C, 0, zer, dp1);
        for (int i = 0; i < neigh[C].size(); i++) {
            int v = neigh[C][i];
            if (rem[v]) continue;
            Solve(v, C, zer, dp0);
        }
        for (auto ind: myquer)
            if (A[ind] == C)
                res[ind] = dp1[B[ind]][V[ind]];
            else if (B[ind] == C)
                res[ind] = dp1[A[ind]][V[ind]];
            else for (int i = 0; i <= V[ind]; i++)
                res[ind] = max(res[ind], dp0[A[ind]][i] + dp1[B[ind]][V[ind] - i]);
    }
    rem[C] = true;
    for (int i = 0; i < neigh[C].size(); i++) {
        int v = neigh[C][i];
        if (rem[v] || nquer[i].empty()) continue;
        Solve(v, nquer[i]);
    }
}

int main() {
    scanf("%d", &T);
    n = s = 1;
    endpoints[s] = {1, 1};
    L[n] = 1;
    while (T--) {
        int typ, x;
        scanf("%d %d", &typ, &x);
        switch (typ) {
            case 1:
                endpoints[++s] = endpoints[x];
                break;
            case 2:
                n++;
                scanf("%d %d", &pt[n].first, &pt[n].second);
                addEdge(endpoints[x].second, n);
                endpoints[x].second = n;
                if (endpoints[x].first == 1)
                    endpoints[x].first = n;
                break;
            case 3:
                if (endpoints[x].first == endpoints[x].second)
                    endpoints[x] = {1, 1};
                else endpoints[x].first = getNext(endpoints[x].first, endpoints[x].second);
                break;
            case 4:
                A[rlen] = endpoints[x].first;
                B[rlen] = endpoints[x].second;
                scanf("%d", &V[rlen]);
                rlen++;
                break;
        }
    }
    vector<int> seq;
    for (int i = 0; i < rlen; i++)
        if (A[i] == B[i])
            res[i] = pt[A[i]].first <= V[i]? pt[A[i]].second: 0;
        else seq.push_back(i);
    Solve(1, seq);
    for (int i = 0; i < rlen; i++)
        printf("%d\n", res[i]);
    return 0;
}
