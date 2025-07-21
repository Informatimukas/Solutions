#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n;
int delt[Maxn];
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill_n(delt, n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            delt[max(0, i - a[i])]++;
            delt[i]--;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += delt[i];
            printf("%d%c", int(ans > 0), i + 1 < n? ' ': '\n');
        }
    }
    return 0;
}
