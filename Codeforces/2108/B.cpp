#include <bits/stdc++.h>
using namespace std;

int T;
int n, x;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        if (n == 1)
            if (x == 0) printf("-1\n");
            else printf("%d\n", x);
        else if (n == 2)
            if (__builtin_popcount(x) >= 2)
                printf("%d\n", x);
            else {
                int res = x;
                int b = 0;
                while (x & 1 << b)
                    b++;
                res += 2 * (1 << b);
                printf("%d\n", res);
            }
        else if (__builtin_popcount(x) >= 2) {
            int lft = n - __builtin_popcount(x);
            int res = x;
            if (lft > 0) res += (lft + 1) / 2 * 2;
            printf("%d\n", res);
        } else {
            int lft = n - __builtin_popcount(x);
            int res = x;
            if (lft % 2 == 0) res += lft;
            else if (n % 2 == x % 2) res += n - x % 2;
            else {
                res += lft / 2 * 2;
                res += 4;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
