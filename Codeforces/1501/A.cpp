#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 105;

int T;
int n;
int a[Maxn], b[Maxn];
int t[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &a[i], &b[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        int tim = 0, lst = 0;
        for (int i = 0; i < n; i++) {
            tim += t[i] + a[i] - lst;
            if (i == n - 1) break;
            tim = max(b[i], tim + (b[i] - a[i] + 1) / 2);
            lst = b[i];
        }
        printf("%d\n", tim);
    }
    return 0;
}