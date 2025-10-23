#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, mod;
    cin >> n >> mod;
    vector<int> dp(n + 1);
    dp[n] = 1;
    dp[n - 1] = mod - 1;
    int ways = 0;
    for (int i = n; i > 0; i--) {
        ways = (ways + dp[i]) % mod;
        dp[i - 1] = (dp[i - 1] + ways) % mod;
        int num = i;
        for (int j = 2, k; j <= num; j = k + 1) {
            int d = num / j;
            k = num / d;
            int add = static_cast<ll>(k - j + 1) * ways % mod;
            dp[d] = (dp[d] + add) % mod;
            dp[d - 1] = (dp[d - 1] - add + mod) % mod;
        }
    }
    cout << ways << "\n";
    return 0;
}