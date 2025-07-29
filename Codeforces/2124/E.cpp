#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> Take(vector<ll>& a, int l, int r, ll need) {
    vector<ll> res(a.size());
    for (int i = l; i <= r; i++) {
        ll tk = min(a[i], need);
        res[i] = tk;
        a[i] -= tk;
        need -= tk;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<ll> a(n + 1), sum(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        if (sum[n] % 2) {
            printf("-1\n");
            continue;
        }
        if (ranges::adjacent_find(sum, [all = sum[n]](ll sum1, ll sum2) {
            return sum1 == all - sum1;
        }) != sum.end()) {
            printf("1\n");
            for (int i = 1; i <= n; i++)
                printf("%lld%c", a[i], " \n"[i == n]);
            continue;
        }
        auto ind = distance(sum.begin(),
            ranges::partition_point(sum, [all = sum[n]](ll sum1) {
                return sum1 < all - sum1;
            }));
        ll lef = sum[ind - 1];
        ll rig = sum[n] - sum[ind];
        if (lef + rig < a[ind]) {
            printf("-1\n");
            continue;
        }
        printf("2\n");
        ll got = (a[ind] + rig - lef) / 2;
        assert(got <= a[ind]);
        auto b = Take(a, ind + 1, n, got);
        b[ind] = got;
        a[ind] -= got;
        for (int i = 1; i <= n; i++)
            printf("%lld%c", b[i], " \n"[i == n]);
        b = Take(a, 1, n, 2 * lef);
        for (int i = 1; i <= n; i++)
            printf("%lld%c", b[i], " \n"[i == n]);
    }
    return 0;
}