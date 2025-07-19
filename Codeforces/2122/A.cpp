#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        if (n == 1 || m == 1 || n == 2 && m == 2)
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
