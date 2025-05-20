#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

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
        int nd = (n - 1) / 2;
        for (int i = 1; i < n; i++)
            if (abs(a[i]) > abs(a[0]))
                nd--;
        printf("%s\n", nd > 0? "NO": "YES");
    }
    return 0;
}
