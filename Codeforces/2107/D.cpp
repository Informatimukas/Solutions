#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const int Maxk = 20;

int T;
int n;
vector <int> neigh[Maxn];
bool rem[Maxn];
int L[Maxn], P[Maxn][Maxk];
vector <iii> res;

void Traverse(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (P[v][0] == u) continue;
        P[u][0] = v;
        L[u] = L[v] + 1;
        Traverse(u);
    }
}

int getLCA(int a, int b)
{
    if (L[a] < L[b])
        swap(a, b);
    for (int i = Maxk - 1; i >= 0; i--)
        if (L[a] - (1 << i) >= L[b])
            a = P[a][i];
    if (a == b) return a;
    for (int i = Maxk - 1; i >= 0; i--)
        if (P[a][i] != P[b][i])
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int getDist(int a, int b)
{
    return L[a] + L[b] - 2 * L[getLCA(a, b)];
}

void Gather(int v, int p, vector <int> &seq)
{
    seq.push_back(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || rem[u]) continue;
        Gather(u, v, seq);
    }
}

void Solve(int v)
{
    vector <int> seq;
    Gather(v, 0, seq);
    sort(seq.begin(), seq.end());
    int best = 0, A = seq[0];
    for (int i = 0; i < seq.size(); i++) {
        int cand = getDist(seq[0], seq[i]);
        if (cand > best) {
            best = cand;
            A = seq[i];
        }
    }
    best = 0;
    int B = A;
    for (int i = 0; i < seq.size(); i++) {
        int cand = getDist(A, seq[i]);
        if (cand > best) {
            best = cand;
            B = seq[i];
        }
    }
    int pnt = int(seq.size()) - 1;
    while (getDist(seq[pnt], A) != best && getDist(seq[pnt], B) != best)
        pnt--;
    int C = seq[pnt];
    while (getDist(seq[pnt], C) != best)
        pnt--;
    int D = seq[pnt];
    res.push_back({best + 1, {C, D}});
    vector <int> got;
    while (C != D) {
        if (L[C] < L[D])
            swap(C, D);
        got.push_back(C);
        rem[C] = true;
        C = P[C][0];
    }
    rem[C] = true;
    got.push_back(C);
    for (int i = 0; i < got.size(); i++)
        for (int j = 0; j < neigh[got[i]].size(); j++) {
            int u = neigh[got[i]][j];
            if (!rem[u]) Solve(u);
        }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            rem[i] = false;
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Traverse(1);
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                P[i][j] = P[P[i][j - 1]][j - 1];
        res.clear();
        Solve(1);
        sort(res.rbegin(), res.rend());
        for (int i = 0; i < res.size(); i++)
            printf("%d %d %d%c", res[i].first,
                res[i].second.first, res[i].second.second,
                i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}
