#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        ll zer = 0;
        for (int i = 2; i <= n; i++)
            zer += i;
        if (zer > x) {
            cout << "0\n";
            continue;
        }
        vector<ll> dp(x + 1);
        dp[zer] = 1;
        for (int i = 1; i <= n - 1; i++)
            for (int j = 0; j + i <= x; j++)
                dp[j + i] = (dp[j + i] + dp[j]) % mod;
        ll res = 0;
        for (int j = 0; j <= x; j++) {
            int my = j == 0 ? x : (x + 1 - j);
            res = (res + my * dp[j]) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
