#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll a = 0, b = 0, both = 0;
        for (int i = 0; i < n; i++) {
            int A, B, C; scanf("%d %d %d", &A, &B, &C);
            a += min(A, B);
            b += min(B, C);
            both += min(B, A + C);
        }
        ll res = min({a, b, both / 2});
        printf("%lld\n", res);
    }
    return 0;
}