#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 20;

int T;
int n, s;
int x[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &s);
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        int res = x[n - 1] - x[0] + min(abs(s - x[0]), abs(s - x[n - 1]));
        printf("%d\n", res);
    }
    return 0;
}
