#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr ll Inf = 1000000000000000000ll;
constexpr int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll mndif = Inf, curmin = Inf;
        ll res = Inf, sum = 0;
        for (int i = 0; i < n; i++) {
            ll a; scanf("%lld", &a);
            if (i)
                res = min(res, sum + min(mndif, a));
            if (a < curmin) {
                mndif = min(mndif, curmin - a);
                curmin = a;
            } else mndif = 0;
            sum += curmin;
        }
        res = min(res, sum);
        printf("%lld\n", res);
    }
    return 0;
}