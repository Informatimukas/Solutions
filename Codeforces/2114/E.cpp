#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
vector <int> neigh[Maxn];
ll res[Maxn];

void Traverse(int v, int par, ll p, ll n)
{
    res[v] = a[v] + n;
    ll np = max(0ll, a[v] + n);
    ll nn = max(0ll, -a[v] + p);
    p = np;
    n = nn;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == par) continue;
        Traverse(u, v, p, n);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        res[1] = a[1];
        Traverse(1, 0, 0, 0);
        for (int i = 1; i <= n; i++)
            printf("%lld%c", res[i], i + 1 <= n? ' ': '\n');
    }
	return 0;
}
