#include <bits/stdc++.h>
using namespace std;

int T;
int a, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &x, &y);
        if (a < min(x, y) || a > max(x, y))
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}