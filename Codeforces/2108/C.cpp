#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int pnt = 0, res = 0;
        while (pnt < n)
            if (pnt + 1 < n && a[pnt] <= a[pnt + 1])
                pnt++;
            else {
                res++;
                while (pnt + 1 < n && a[pnt] >= a[pnt + 1])
                    pnt++;
                pnt++;
            }
        printf("%d\n", res);
    }
    return 0;
}
