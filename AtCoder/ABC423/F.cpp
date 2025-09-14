#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Gcd(ll x, ll y) { return x ? Gcd(y % x, x) : y; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    ll y;
    cin >> n >> m >> y;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x;
    vector dp(1 << n, 0ll);
    for (int i = 0; i < 1 << n; i++)
        if (__builtin_popcount(i) == m)
            dp[i] = 1;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < 1 << n; i++)
            if (!(i & 1 << j))
                dp[i | 1 << j] -= dp[i];
    ll res = 0;
    for (int i = 0; i < 1 << n; i++) {
        ll lcm = 1;
        for (int j = 0; j < n; j++)
            if (i & 1 << j) {
                lcm /= Gcd(lcm, a[j]);
                if (lcm <= y / a[j])
                    lcm *= a[j];
                else lcm = y + 1;
            }
        res += y / lcm * dp[i];
    }
    cout << res << "\n";
    return 0;
}
