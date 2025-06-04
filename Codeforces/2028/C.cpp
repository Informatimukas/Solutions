#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, m, w;
int a[Maxn];
ll sum[Maxn];
int L[Maxn], R[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &w);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++)
            if (sum[i] < w) L[i] = 0;
            else {
                int lef = 1, rig = i;
                while (lef <= rig) {
                    int mid = lef + rig >> 1;
                    if (sum[i] - sum[mid - 1] >= w)
                        lef = mid + 1;
                    else rig = mid - 1;
                }
                L[i] = L[rig - 1] + 1;
            }
        if (L[n] < m) {
            printf("-1\n");
            continue;
        }
        R[n + 1] = 0;
        for (int i = n; i >= 1; i--)
            if (sum[n] - sum[i - 1] < w) R[i] = 0;
            else {
                int lef = i, rig = n;
                while (lef <= rig) {
                    int mid = lef + rig >> 1;
                    if (sum[mid] - sum[i - 1] >= w)
                        rig = mid - 1;
                    else lef = mid + 1;
                }
                R[i] = R[lef + 1] + 1;
            }
        ll res = 0;
        int pnt = 1;
        for (int i = 1; i <= n; i++) {
            while (pnt <= i && L[pnt - 1] + R[i + 1] < m)
                pnt++;
            if (pnt <= i)
                res = max(res, sum[i] - sum[pnt - 1]);
        }
        printf("%lld\n", res);
    }
	return 0;
}
