#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return static_cast<ll>(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector dp(n + 1, 0);
    dp[0] = (mod - 1) % mod;
    for (int i = 0; i < n; i++)
        for (int j = i; j >= 0; j--) {
            dp[j + 1] = (dp[j + 1] + static_cast<ll>(mod - 1) * dp[j]) % mod;
            dp[j] = static_cast<ll>(dp[j]) * a[i] % mod;
        }
    int cur = 1;
    int inv = Inv(n);
    int res = 0;
    for (int k = 1; k <= n && k <= K; k++) {
        cur = static_cast<ll>(cur) * (K + 1 - k) % mod * inv % mod;
        res = (res + static_cast<ll>(cur) * dp[k]) % mod;
    }
    cout << res << "\n";
    return 0;
}
