#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxb = 60;

int T;
int n;
ll a[Maxn];
ll b[Maxn];
char c[Maxn];
ll xr[Maxb];
int wh[Maxb];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        ll res = 0ll;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
            res ^= b[i];
            a[i] ^= b[i];
        }
        scanf("%s", c);
        fill(xr, xr + Maxb, 0ll);
        for (int i = n - 1; i >= 0; i--)
            for (int j = Maxb - 1; j >= 0; j--)
                if (a[i] & 1ll << ll(j))
                    if (xr[j]) a[i] ^= xr[j];
                    else {
                        xr[j] = a[i];
                        wh[j] = c[i] - '0';
                        break;
                    }
        for (int j = Maxb - 1; j >= 0; j--)
            if (xr[j])
                if (bool(res & 1ll << ll(j)) != bool(wh[j]))
                    res ^= xr[j];
        printf("%lld\n", res);
    }
	return 0;
}
