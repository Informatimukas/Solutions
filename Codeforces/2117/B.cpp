#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
            printf("%d ", i);
        printf("1\n");
    }
    return 0;
}