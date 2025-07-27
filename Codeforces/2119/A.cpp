#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 2000000000;

int T;
int a, b, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &x, &y);
        int res = Inf;
        if ((a ^ b) == 1)
            res = min(res, y);
        if (a <= b) {
            int cand = 0;
            while (a < b)
                if ((a & 1) == 0) {
                    cand += min(x, y);
                    a++;
                } else {
                    cand += x;
                    a++;
                }
            res = min(res, cand);
        }
        printf("%d\n", res < Inf? res: -1);
    }
    return 0;
}