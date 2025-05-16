#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);;
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        int s = a + b + c;
        if (s % 3 == 0 && s / 3 >= b)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
