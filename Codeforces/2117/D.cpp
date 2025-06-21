#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n;
int a[Maxn];

bool Check() {
    int dif = a[1] - a[0];
    if (dif < 0 || dif > a[0]) return false;
    for (int i = 1; i + 1 < n; i++)
        if (a[i + 1] - a[i] != dif) return false;
    return (a[0] - dif) % (n + 1) == 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (Check()) {
            printf("YES\n");
            continue;
        }
        reverse(a, a + n);
        printf("%s\n", Check() ? "YES" : "NO");
    }
    return 0;
}