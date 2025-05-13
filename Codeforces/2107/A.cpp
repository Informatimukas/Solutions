#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

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
        int mx = *max_element(a, a + n);
        int mn = *min_element(a, a + n);
        if (mn == mx)
            printf("No\n");
        else {
            printf("Yes\n");
            for (int i = 0; i < n; i++)
                printf("%d%c", a[i] == mx? 1: 2, i + 1 < n? ' ': '\n');
        }
    }
    return 0;
}
