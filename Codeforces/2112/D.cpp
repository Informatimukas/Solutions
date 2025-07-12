#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
int A[Maxn], B[Maxn];
vector<ii> neigh[Maxn];

void setEdge(int ind, int v, int wh) {
    if (A[ind] == v ^ wh == 1)
        swap(A[ind], B[ind]);
}

void setAll(int v, int p, int wh) {
    for (auto [u, ind] : neigh[v]) {
        if (u == p) continue;
        setEdge(ind, v, wh);
        setAll(u, v, 1 - wh);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &A[i], &B[i]);
            neigh[A[i]].emplace_back(B[i], i);
            neigh[B[i]].emplace_back(A[i], i);
        }
        int r = 1;
        while (r <= n && neigh[r].size() != 2)
            r++;
        if (r > n) {
            printf("NO\n");
            continue;
        }
        setEdge(neigh[r][0].second, r, 0);
        setAll(neigh[r][0].first, r, 1);
        setEdge(neigh[r][1].second, r, 1);
        setAll(neigh[r][1].first, r, 0);
        printf("YES\n");
        for (int i = 0; i < n - 1; i++)
            printf("%d %d\n", A[i], B[i]);
    }
    return 0;
}