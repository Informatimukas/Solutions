#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;
constexpr int mod = 1000000007;

int pw2[Maxn];
int T;
int n;
vector<int> neigh[Maxn];

ii Solve1(int v, int p) {
    int ch = 0;
    ii g = {1, 0};
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ch++;
        g = Solve1(u, v);
    }
    if (ch > 1) return {0, 0};
    return {g.first, g.second + 1};
}

int Take(int a, int b) {
    if (a <= b) return 2 * a;
    return 2 * b + 1;
}

int Solve2(int v, int p) {
    int ch = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        ch++;
    }
    if (ch > 2) return 0;
    if (ch == 2) {
        vector<int> ways;
        for (int i = 0; i < neigh[v].size(); i++) {
            int u = neigh[v][i];
            if (u == p) continue;
            ii got = Solve1(u, v);
            if (got.first == 0) return 0;
            ways.push_back(got.second);
        }
        return (pw2[ways[0] + ways[1] - Take(ways[0], ways[1])] +
                pw2[ways[0] + ways[1] - Take(ways[1], ways[0])]) % mod * 2 % mod;
    }
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        return Solve2(u, v) * 2 % mod;
    }
    return 2;
}

int main() {
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        printf("%d\n", Solve2(1, 0));
    }
    return 0;
}