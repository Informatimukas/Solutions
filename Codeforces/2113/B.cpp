#include <bits/stdc++.h>
using namespace std;

int T;
int w, h, a, b;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &w, &h, &a, &b);
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        bool res = x1 == x2 && abs(y1 - y2) % b == 0 ||
                   y1 == y2 && abs(x1 - x2) % a == 0 ||
                       x1 != x2 && y1 != y2 && (abs(x1 - x2) % a == 0 || abs(y1 - y2) % b == 0);
        printf("%s\n", res ? "Yes" : "No");
    }
    return 0;
}