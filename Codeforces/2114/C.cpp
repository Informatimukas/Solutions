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
        sort(a, a + n);
        int lst = -10, res = 0;
        for (int i = 0; i < n; i++)
            if (lst + 1 < a[i]) {
                res++;
                lst = a[i];
            }
        printf("%d\n", res);
    }
	return 0;
}
