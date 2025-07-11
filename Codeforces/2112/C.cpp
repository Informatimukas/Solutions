#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 5005;

int T;
int n;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int rig = i + 1, lef = n - 1;
            for (int j = 0; j < i; j++) {
                while (rig < n && a[i] + a[j] > a[rig]) rig++;
                while (lef > i && a[i] + a[j] > a[n - 1] - a[lef]) lef--;
                if (lef < rig)
                    res += rig - lef - 1;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}