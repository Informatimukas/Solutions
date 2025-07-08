#include <bits/stdc++.h>
using namespace std;

int T;
int l1, b1, l2, b2, l3, b3;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d", &l1, &b1, &l2, &b2, &l3, &b3);
        if (l1 == l2 && l2 == l3 && l1 == b1 + b2 + b3 ||
            b1 == b2 && b2 == b3 && b1 == l1 + l2 + l3 ||
            l3 + l2 == l1 && b3 == b2 && l1 == b2 + b1 ||
            b3 + b2 == b1 && l3 == l2 && b1 == l2 + l1)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}