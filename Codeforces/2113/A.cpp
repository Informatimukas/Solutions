#include <bits/stdc++.h>
using namespace std;

int T;
int k, a, b, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &k, &a, &b, &x, &y);
        if (x > y) {
            swap(a, b);
            swap(x, y);
        }
        int res = 0;
        if (k >= a) {
            int tk = (k - a) / x + 1;
            res += tk;
            k -= tk * x;
        }
        if (k >= b) {
            int tk = (k - b) / y + 1;
            res += tk;
            k -= tk * y;
        }
        printf("%d\n", res);
    }
    return 0;
}