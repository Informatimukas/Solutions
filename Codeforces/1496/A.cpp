#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 105;

int T;
int n, k;
char str[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        bool ok = 2 * k + 1 <= n;
        for (int i = 0; i < k && ok; i++)
            ok = str[i] == str[n - 1 - i];
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}