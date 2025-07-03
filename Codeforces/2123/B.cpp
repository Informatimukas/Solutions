#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n, j, k;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &j, &k);
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            mx = max(mx, a[i]);
        }
        if (k > 1 || mx == a[j])
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}