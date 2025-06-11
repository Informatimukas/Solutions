#include <bits/stdc++.h>
using namespace std;

const int lim = 50000;

void Solve(int p, int s)
{
    for (int x = 0; 1 + x <= lim; x++) {
        int w = x / 2;
        int h = x - w;
        int A = x * (2 * s - p) + 4 * s - p;
        if (A % p == 0) {
            int y = A / p;
            if (y >= 0 && 1 + x + y <= lim && y <= w * h) {
                printf("%d\n", 1 + x + y);
                printf("0 0\n");
                for (int i = 1; i <= h; i++)
                    printf("%d 0\n", i);
                for (int i = 1; i <= w; i++)
                    printf("0 %d\n", i);
                for (int i = 1; i <= h && y > 0; i++)
                    for (int j = 1; j <= w && y > 0; j++) {
                        printf("%d %d\n", i, j);
                        y--;
                    }
                return;
            }
        }
    }
    printf("-1\n");
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int p, s; scanf("%d %d", &p, &s);
        Solve(p, s);
    }
    return 0;
}