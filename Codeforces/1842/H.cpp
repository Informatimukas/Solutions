#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector my(n, array<int, 2>());
    while (m--) {
        int t, i, j;
        cin >> t >> i >> j;
        i--;
        j--;
        my[i][t] |= 1 << j;
        my[j][t] |= 1 << i;
    }
    vector dp(1 << n, 0);
    dp[(1 << n) - 1] = 1;
    for (int i = (1 << n) - 1; i > 0; i--)
        for (int j = 0; j < n; j++)
            if (i & 1 << j) {
                int cnt = 0;
                for (int k = 0; k < 2; k++)
                    if (!(i & my[j][k]))
                        cnt++;
                dp[i ^ 1 << j] = (dp[i ^ 1 << j] + static_cast<ll>(cnt) * dp[i]) % mod;
            }
    int inv = 1;
    for (int i = 1; i <= n; i++)
        inv = 2ll * i % mod * inv % mod;
    int res = static_cast<ll>(dp[0]) * Inv(inv) % mod;
    cout << res << "\n";
    return 0;
}
