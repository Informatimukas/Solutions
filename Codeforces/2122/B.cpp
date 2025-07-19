#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        ll res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if (b > d)
                res += a + b - d;
            else if (a > c)
                res += a - c;
        }
        printf("%lld\n", res);
    }
    return 0;
}