#include <bits/stdc++.h>
using namespace std;

int T;
int n, s;

int main() {
    scanf("%d", &T);
    while (T--) {
        int res = 0;
        scanf("%d %d", &n, &s);
        for (int i = 0; i < n; i++) {
            int dx, dy, x, y;
            scanf("%d %d %d %d", &dx, &dy, &x, &y);
            if (dx == 1) x = (s - x) % s;
            if (dy == 1) y = (s - y) % s;
            if (x == y) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}