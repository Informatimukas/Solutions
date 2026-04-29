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
        vector<ll> l(n), f(n), s(n);
        for (int i = 0; i < n; i++) {
            f[i] = i == 0 ? 1 : __gcd(a[i - 1], a[i]);
            s[i] = i == n - 1 ? 1 : __gcd(a[i], a[i + 1]);
            l[i] = f[i] / __gcd(f[i], s[i]) * s[i];
        }
        vector dp(primes.size(), -Inf);
        int sam = 0;
        for (int i = 0; i < n; i++) {
            vector ndp(primes.size(), -Inf);
            int nsam = sam;
            for (int j = 0; j < primes.size(); j++)
                if (dp[j] >= 0) {
                    if (i == 0 || __gcd(static_cast<ll>(primes[j]) * l[i - 1],
                        static_cast<ll>(a[i])) == f[i])
                        nsam = max(nsam, dp[j]);
                    for (int k = 0; k < primes.size() && l[i] * primes[k] <= b[i]; k++)
                        if (l[i] * primes[k] != a[i] &&
                            (i == 0 ||
                                __gcd(l[i] * primes[k], l[i - 1] * primes[j]) == f[i]))
                            ndp[k] = max(ndp[k], dp[j] + 1);
                }
            for (int k = 0; k < primes.size() && l[i] * primes[k] <= b[i]; k++)
                if (l[i] * primes[k] != a[i] &&
                    (i == 0 || __gcd(l[i] * primes[k], static_cast<ll>(a[i - 1])) == f[i]))
                    ndp[k] = max(ndp[k], sam + 1);
            dp = std::move(ndp);
            sam = nsam;
        }
        cout << max(sam, *ranges::max_element(dp)) << "\n";
    }
    return 0;
}
