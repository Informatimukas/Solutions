#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;

constexpr ll Inf = 1000000000000000000ll;
constexpr int Maxn = 200005;

int T;
int n;
int P[Maxn];
vector<int> neigh[Maxn];
lli dp[Maxn][2];
int cnt[Maxn];
int res[Maxn];
vector<int> seq[Maxn];
int my[Maxn];

void Traverse(int v) {
    cnt[v] = 1;
    dp[v][0] = {0, 0};
    dp[v][1] = {-Inf, 0};
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == P[v]) continue;
        P[u] = v;
        Traverse(u);
        cnt[v] += cnt[u];
        dp[u][1].first += min(cnt[u] - 1, n - cnt[u]);
        dp[u][1] = max(dp[u][1], {dp[u][0].first, u});
        dp[u][0].first += min(cnt[u], n - 1 - cnt[u]);
        lli cand1 = {dp[u][0].first + dp[v][1].first, dp[v][1].second};
        lli cand2 = {dp[u][1].first + dp[v][0].first, dp[u][1].second};
        dp[v][0].first += dp[u][0].first;
        dp[v][1] = max(cand1, cand2);
    }
}

void Solve(int v, int p, int forb, int &lft) {
    seq[my[v]].push_back(v);
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p || u == forb) continue;
        Solve(u, v, forb, lft);
        while (seq[my[v]].size() + seq[my[u]].size() > lft / 2) {
            int a = seq[my[v]].back();
            seq[my[v]].pop_back();
            int b = seq[my[u]].back();
            seq[my[u]].pop_back();
            res[a] = res[b] = lft / 2;
            lft -= 2;
        }
        if (seq[my[v]].size() < seq[my[u]].size())
            swap(my[v], my[u]);
        seq[my[v]].insert(seq[my[v]].end(), seq[my[u]].begin(), seq[my[u]].end());
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            res[i] = 0;
            seq[i].clear();
            my[i] = i;
        }
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            scanf("%d %d", &v, &u);
            neigh[v].push_back(u);
            neigh[u].push_back(v);
        }
        Traverse(1);
        int a = dp[1][1].second;
        int b = P[a];
        printf("%d %d\n", a, b);
        if (a > b) swap(a, b);
        for (int i = 0; i < neigh[b].size(); i++) {
            int u = neigh[b][i];
            if (u == a) continue;
            neigh[a].push_back(u);
            neigh[u].push_back(a);
        }
        int lft = n - 1;
        Solve(1, 0, b, lft);
        for (int i = 1; i <= n; i++)
            printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}