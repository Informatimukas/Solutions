#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

constexpr int Maxn = 200005;
constexpr int Maxp = 2000;
constexpr int Maxm = 105;

int T;
int n, q;
int a[Maxn];
vector<ii> neigh[Maxn];
ll sum;
int bigind[Maxn];
int blen;
ll big[Maxm][Maxn];
vector<ii> bigs[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            neigh[i].clear();
            bigind[i] = 0;
        }
        sum = 0;
        for (int i = 0; i < n - 1; i++) {
            int u, v, c; scanf("%d %d %d", &u, &v, &c);
            neigh[u].emplace_back(v, c);
            neigh[v].emplace_back(u, c);
            if (a[u] != a[v])
                sum += c;
        }
        blen = 0;
        for (int i = 1; i <= n; i++)
            if (neigh[i].size() > Maxp) {
                ++blen;
                fill_n(big[blen], n + 1, 0ll);
                bigind[i] = blen;
                for (auto& [v, cost]: neigh[i])
                    big[blen][a[v]] += cost;
            }
        for (int i = 1; i <= n; i++) {
            bigs[i].clear();
            for (auto& [v, cost]: neigh[i])
                if (bigind[v])
                    bigs[i].emplace_back(bigind[v], cost);
        }
        while (q--) {
            int v, x; scanf("%d %d", &v, &x);
            for (auto& [b, cost]: bigs[v]) {
                big[b][a[v]] -= cost;
                big[b][x] += cost;
            }
            if (bigind[v]) {
                sum += big[bigind[v]][a[v]];
                a[v] = x;
                sum -= big[bigind[v]][a[v]];
            } else {
                for (auto& [u, cost]: neigh[v]) {
                    int delt = static_cast<int>(a[v] == a[u]) - static_cast<int>(x == a[u]);
                    if (delt) sum += delt * cost;
                }
                a[v] = x;
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}
