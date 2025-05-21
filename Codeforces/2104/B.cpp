#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
ll sum[Maxn];
ll res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sum[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            sum[i] = sum[i + 1] + a[i];
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, a[i - 1]);
            res[n - i + 1] = mx + sum[i];
        }
        for (int i = 1; i <= n; i++)
            printf("%lld%c", res[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}
