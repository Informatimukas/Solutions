#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 105;

int T;
int n;
int a[Maxn];

void Solve() {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                printf("YES\n");
                printf("2\n");
                printf("%d %d\n", a[i], a[j]);
                return;
            }
    printf("NO\n");
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        Solve();
    }
    return 0;
}
