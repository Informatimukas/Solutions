#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 1000005;
constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector mult(Maxn, 1);
    mult[1] = -1;
    vector prime(Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i])
        for (int j = i; j < Maxn; j += i) {
            prime[j] = false;
            int d = j / i;
            if (d % i == 0) {
                mult[j] = 0;
                continue;
            }
            mult[j] = -mult[d];
        }
    vector<vector<int>> divs(Maxn);
    for (int i = 2; i < Maxn; i++)
        if (mult[i])
            for (int j = i; j < Maxn; j += i)
                divs[j].push_back(i);
    int n;
    cin >> n;
    int a;
    cin >> a;
    vector<int> dp(Maxn);
    for (auto d : divs[a])
        dp[d] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        int ways = 0;
        for (auto d : divs[a]) {
            ways += dp[d] * mult[d];
            if (ways < 0)
                ways += mod;
            else if (ways >= mod)
                ways -= mod;
        }
        if (i == n) {
            cout << ways << "\n";
            break;
        }
        for (auto d : divs[a])
            dp[d] = (dp[d] + ways) % mod;
    }
    return 0;
}
