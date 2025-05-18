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
int L[Maxn], P[Maxn];
vector <iii> res;

void getLevels(int v)
{
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        P[u] = v;
        L[u] = L[v] + 1;
        getLevels(u);
    }
}

ii Traverse(int v, int p)
{
    ii res = {0, v};
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || rem[u]) continue;
        ii got = Traverse(u, v);
        res = max(res, {got.first + 1, got.second});
    }
    return res;
}

void Solve(int v)
{
    int A = Traverse(v, 0).second;
    int B = Traverse(A, 0).second;
    int C = Traverse(B, 0).second;
    C = max(C, B);
    ii d = Traverse(C, 0);
    int D = d.second;
    int dist = d.first;
    res.push_back({dist + 1, {C, D}});
    vector <int> got;
    while (C != D) {
        if (L[C] < L[D])
            swap(C, D);
        got.push_back(C);
        rem[C] = true;
        C = P[C];
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
        getLevels(1);
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
