#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 200005;

int T;
int n, k;
int a[Maxn];

ll getSum(ll n) { return static_cast<ll>(n + 1) * n / 2; }

ll getSum(ll l, ll r) { return getSum(r) - getSum(l - 1); }

ll getLeft(ll x) {
    for (int i = 0; i + 1 < n; i++)
        if (static_cast<ll>(a[i + 1] - a[i]) * (i + 1) <= x)
            x -= static_cast<ll>(a[i + 1] - a[i]) * (i + 1);
        else return a[i] + (x + i) / (i + 1);
    return a[n - 1] + (x + n - 1) / n;
}

ll getRight(ll x) {
    for (int i = n - 1; i > 0; i--)
        if (static_cast<ll>(a[i] - a[i - 1]) * (n - i) <= x)
            x -= static_cast<ll>(a[i] - a[i - 1]) * (n - i);
        else return a[i] + 1 - (x + n - i - 1) / (n - i);
    return a[0] + 1 - (x + n - 1) / n;
}

ll solveLeft(ll x) {
    ll res = 0ll;
    for (int i = 0; i + 1 < n; i++)
        if (static_cast<ll>(a[i + 1] - a[i]) * (i + 1) <= x) {
            x -= static_cast<ll>(a[i + 1] - a[i]) * (i + 1);
            res += getSum(a[i] + 1, a[i + 1]) * (i + 1);
        } else {
            ll full = x / (i + 1);
            res += getSum(a[i] + 1, a[i] + full) * (i + 1);
            res += (a[i] + full + 1) * (x % (i + 1));
            return res;
        }
    ll full = x / n;
    res += getSum(a[n - 1] + 1, a[n - 1] + full) * n;
    res += (a[n - 1] + full + 1) * (x % n);
    return res;
}

ll solveRight(ll x) {
    ll res = 0ll;
    for (int i = n - 1; i > 0; i--)
        if (static_cast<ll>(a[i] - a[i - 1]) * (n - i) <= x) {
            x -= static_cast<ll>(a[i] - a[i - 1]) * (n - i);
            res -= getSum(a[i - 1] + 1, a[i]) * (n - i);
        } else {
            ll full = x / (n - i);
            res -= getSum(a[i] + 1 - full, a[i]) * (n - i);
            res -= (a[i] - full) * (x % (n - i));
            return res;
        }
    ll full = x / n;
    res -= getSum(a[0] + 1 - full, a[0]) * n;
    res -= (a[0] - full) * (x % n);
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += getSum(a[i]);
        }
        sort(a, a + n);
        ll lef = 1, rig = 1000000000000ll;
        while (lef <= rig) {
            ll mid = lef + rig >> 1ll;
            if (getLeft(mid) + k < getRight(mid))
                lef = mid + 1ll;
            else rig = mid - 1ll;
        }
        sum += solveLeft(rig) + solveRight(rig) + rig * k;
        printf("%lld\n", sum);
    }
    return 0;
}
