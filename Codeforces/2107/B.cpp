#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        if (max(a[n - 1] - 1, a[n - 2]) - a[0] > k || sum % 2 == 0)
            printf("Jerry\n");
        else printf("Tom\n");
    }
    return 0;
}
