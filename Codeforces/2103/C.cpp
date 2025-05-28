#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn], na[Maxn];

bool Check2(int a[], int k)
{
    int lst = Maxn;
    int cur = 0;
    for (int i = 0; i + 1 < n; i++) {
        cur += a[i] > k? -1: 1;
        if (cur >= lst) return true;
        if (cur >= 0)
            lst = min(lst, cur);
    }
    return false;
}

int Check1(int a[], int k)
{
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i] > k? -1: 1;
        if (cur >= 0) return i + 1;
    }
    return n + 1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            na[n - 1 - i] = a[i];
        }
        if (Check2(a, k) || Check2(na, k) || Check1(a, k) + Check1(na, k) < n)
            printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
