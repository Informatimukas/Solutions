#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

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
        int res = 0;
        for (int z = 0; z < 2; z++) {
            array dp{0, 0};
            for (int i = 0; i < 2; i++)
                if (s[0] == '?' || s[0] == '0' + i)
                    dp[i] = 1;
            for (int i = 1; i < n; i++) {
                int nd = i % 2 ? z : 1 - z;
                array ndp{0, 0};
                for (int k = 0; k < 2; k++)
                    if (s[i] == '?' || s[i] == '0' + k)
                        for (int j = 0; j < 2; j++)
                            if ((j + k) % 2 == nd)
                                ndp[k] = (ndp[k] + dp[j]);
                dp = ndp;
            }
            res = (res + dp[0]) % mod;
            res = (res + dp[1]) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
