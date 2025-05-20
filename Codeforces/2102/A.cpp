#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, p, q;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &p, &q);
        if (n % p || n / p * q == m)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
