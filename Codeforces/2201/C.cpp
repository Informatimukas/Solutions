#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> sum(n);
        for (int i = 0; i < s.length(); i++) {
            sum[i] = s[i] == '(' ? 1 : -1;
            if (i)
                sum[i] += sum[i - 1];
        }
        array<ll, 2> dp{};
        ll pw2 = 1, res = 0;
        for (int i = 0; i < s.length(); i++, pw2 = 2ll * pw2 % mod) {
            if (s[i] == '(')
                res = (res + pw2) % mod;
            array<ll, 2> ndp{};
            for (int j = 0; j < 2; j++) {
                // don't use
                if (sum[i] - 2 * j >= 0)
                    ndp[j] = (ndp[j] + dp[j]) % mod;
                // use
                if (s[i] == '(' && sum[i] >= 2)
                    ndp[1] = (ndp[1] + dp[j]) % mod;
                else if (s[i] == ')') {
                    ndp[0] = (ndp[0] + dp[j]) % mod;
                    res = (res + dp[j]) % mod;
                }
            }
            if (s[i] == '(' && sum[i] >= 2)
                ndp[1] = (ndp[1] + 1) % mod;
            else if (s[i] == ')') {
                res = (res + 1) % mod;
                ndp[0] = (ndp[0] + 1) % mod;
            }
            swap(dp, ndp);
        }
        cout << res << "\n";
    }
    return 0;
}
