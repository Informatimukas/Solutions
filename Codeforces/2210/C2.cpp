#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const vector primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        vector<int> l(n), f(n), s(n);
        for (int i = 0; i < n; i++) {
            f[i] = i == 0 ? 1 : __gcd(a[i - 1], a[i]);
            s[i] = i == n - 1 ? 1 : __gcd(a[i], a[i + 1]);
            l[i] = f[i] / __gcd(f[i], s[i]) * s[i];
        }
        vector dp(primes.size(), -Inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector ndp(primes.size(), -Inf);

            if (l[i] != a[i] && lcm <= b[i])
                ndp[0] = *ranges::max_element(dp) + 1;
            else ndp[0] = *ranges::max_element(dp);
            for (int j = 0; j < ndp.size() && static_cast<ll>(lcm) * primes[j] != a[i] &&
                static_cast<ll>(lcm) * primes[j] <= b[i]; j++) {
                if (i < n - 1) {
                    ll g = __gcd(static_cast<ll>(lcm) * primes[j], static_cast<ll>(a[i + 1]));
                    if (g != s) continue;
                }
                for (int k = 0; k < dp.size(); k++)
                    if (dp[k] >= 0) {
                        if (i > 0) {
                            ll g = __gcd(static_cast<ll>(lcm) * primes[j],
                                static_cast<ll>(a[i - 1]) * primes[k]);
                            if (g != f)
                                continue;
                        }
                        ndp[j] = max(ndp[j], dp[k] + 1);
                    }
            }
            dp = std::move(ndp);
        }
        cout << *ranges::max_element(dp) << "\n";
    }
    return 0;
}
