#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n, st, en;
vector<int> neigh[Maxn];
vector<int> res;

void Traverse(int v, int p) {
    for (auto &u: neigh[v]) {
        if (u == p) continue;
        Traverse(u, v);
    }
    res.push_back(v);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &st, &en);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        res.clear();
        Traverse(en, -1);
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}
