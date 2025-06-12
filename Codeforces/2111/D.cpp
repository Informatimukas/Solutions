#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n, m;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        sort(a, a + m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                printf("%d %d%c", a[i], a[m - 1 - i], j + 1 < 3 ? ' ' : '\n');
    }
    return 0;
}