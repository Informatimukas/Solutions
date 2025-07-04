#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;
constexpr int Inf = 1000000000;

int T;
int n;
int a[Maxn];
char res[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            res[i] = '0';
        }
        res[n] = '\0';
        int mn = Inf;
        for (int i = 0; i < n; i++) {
            mn = min(mn, a[i]);
            if (mn == a[i])
                res[i] = '1';
        }
        int mx = -Inf;
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, a[i]);
            if (mx == a[i])
                res[i] = '1';
        }
        printf("%s\n", res);
    }
    return 0;
}