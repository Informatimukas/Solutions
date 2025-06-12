#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int T;
int n;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ll res = 8000000000000000000ll;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[i] == a[j])
                j++;
            res = min(res, static_cast<ll>(n - (j - i)) * a[i]);
        }
        printf("%lld\n", res);
    }
    return 0;
}
