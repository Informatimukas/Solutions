#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 12;

int T;
int n, x;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int lef = 0, rig = n - 1;
        while (a[lef] == 0)
            lef++;
        while (a[rig] == 0)
            rig--;
        printf("%s\n", x > rig - lef? "YES" : "NO");
    }
    return 0;
}