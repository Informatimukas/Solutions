#include <bits/stdc++.h>
using namespace std;

int T;
int x;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        int mn = 10;
        while (x) {
            mn = min(mn, x % 10);
            x /= 10;
        }
        printf("%d\n", mn);
    }
    return 0;
}