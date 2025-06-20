#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", 2 * n - 1);
        for (int i = 1; i <= n; i++) {
            printf("%d 1 %d\n", i, i);
            if (i < n)
                printf("%d %d %d\n", i, i + 1, n);
        }
    }
    return 0;
}
