#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 100005;

int T;
int n;
ll p[Maxn];
ll s[Maxn];
ll res[Maxn];

ll Gcd(ll x, ll y) { return x? Gcd(y % x, x): y; }

ll Lcm(ll x, ll y) { return x / Gcd(x, y) * y; }

bool Check() {
    ll cur = 1;
    for (int i = n; i > 0; i--) {
        if (p[i] % cur) return false;
        cur = p[i];
        res[i] = Lcm(res[i], cur);
    }
    cur = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] % cur) return false;
        cur = s[i];
        res[i] = Lcm(res[i], cur);
    }
    cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = Gcd(cur, res[i]);
        if (cur != p[i])
            return false;
    }
    cur = 0;
    for (int i = n; i > 0; i--) {
        cur = Gcd(cur, res[i]);
        if (cur != s[i])
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &p[i]);
            res[i] = 1;
        }
        for (int i = 1; i <= n; i++)
            scanf("%lld", &s[i]);
        printf("%s\n", Check() ? "YES" : "NO");
    }
    return 0;
}
