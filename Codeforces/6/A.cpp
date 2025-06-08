#include <bits/stdc++.h>
using namespace std;

const int Maxd = 4;

int a[Maxd];

int main()
{
    for (int i = 0; i < Maxd; i++)
        scanf("%d", &a[i]);
    sort(a, a + Maxd);
    if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3])
        printf("TRIANGLE\n");
    else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3])
        printf("SEGMENT\n");
    else printf("IMPOSSIBLE\n");
    return 0;
}
