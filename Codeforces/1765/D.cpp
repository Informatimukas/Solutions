#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 200005;

int n, m;
int a[Maxn];
ll res;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        res += a[i] + 1;
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l < r)
        if (a[l] + a[r] <= m) {
            r--;
            res--;
            if (l < r) {
                l++;
                res--;
            }
        } else r--;
    printf("%lld\n", res);
    return 0;
}