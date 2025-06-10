#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while (T--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bool first;
        if (a >= b)
            first = c >= b || c >= d;
        else first = !(d > a || d > c);
        printf("%s\n", first? "Gellyfish": "Flower");
    }
    return 0;
}