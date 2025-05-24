#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000007;

int T;
int n, m;
int a[Maxn];
int b[Maxn];
int L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (cur < m && a[i] >= b[cur + 1])
                cur++;
            L[i] = cur;
        }
        if (L[n] >= m) {
            printf("0\n");
            continue;
        }
        R[n + 1] = 0;
        cur = 0;
        for (int i = n; i >= 1; i--) {
            if (cur < m && a[i] >= b[m - cur])
                cur++;
            R[i] = cur;
        }
        int res = Inf;
        for (int i = 0; i <= n; i++)
            if (L[i] + R[i + 1] == m - 1)
                res = min(res, b[L[i] + 1]);
        printf("%d\n", res >= Inf? -1: res);
    }
    return 0;
}
