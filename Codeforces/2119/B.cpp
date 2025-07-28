#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;
int px, py, qx, qy;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%d %d %d %d", &px, &py, &qx, &qy);
        int sum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            sum += a;
            mx = max(mx, a);
        }
        ll small = mx >= sum - mx? mx - (sum - mx): 0;
        small = small * small;
        ll dist = static_cast<ll>(px - qx) * (px - qx) +
            static_cast<ll>(py - qy) * (py - qy);
        ll sum2 = static_cast<ll>(sum) * sum;
        if (dist <= sum2 && dist >= small)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}