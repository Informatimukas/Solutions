#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int T;
ll BIT[Maxn][Maxn];
int n, q;

void Add(int x, int y, ll val)
{
    for (int i = x; i < Maxn; i += i & -i)
        for (int j = y; j < Maxn; j += j & -j)
            BIT[i][j] += val;
}

ll Get(ll BIT[], int x)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

ll Get(int x, int lef, int rig)
{
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += Get(BIT[i], rig) - Get(BIT[i], lef - 1);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        fill((ll*)BIT, (ll*)BIT + Maxn * Maxn, 0ll);
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; i++) {
            int h, w; scanf("%d %d", &h, &w);
            Add(h, w, h * w);
        }
        while (q--) {
            int h1, w1, h2, w2;
            scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
            printf("%lld\n", Get(h2 - 1, w1 + 1, w2 - 1) - Get(h1, w1 + 1, w2 - 1));
        }
    }
	return 0;
}
