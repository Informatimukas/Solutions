#include <bits/stdc++.h>
using namespace std;

int T;
int n, x;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 0; i < x; i++)
            printf("%d ", i);
        for (int i = n - 1; i >= x; i--)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}
