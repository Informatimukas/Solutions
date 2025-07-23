#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n, k;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        int pnt = 1, res = 0;
        while (pnt <= n)
            if (pnt + k - 1 <= n && a[pnt + k - 1] - a[pnt - 1] == 0) {
                res++;
                pnt += k + 1;
            } else pnt++;
        printf("%d\n", res);
    }
    return 0;
}