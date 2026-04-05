#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    vector<ll> dp(T.length() + 1);
    ll res = 0;
    for (auto ch : S) {
        dp[0]++;
        for (int j = T.length() - 1; j >= 0; j--)
            if (T[j] == ch) {
                dp[j + 1] += dp[j];
                dp[j] = 0;
            }
        for (int j = 0; j < T.length(); j++)
            res += dp[j];
    }
    cout << res << "\n";
    return 0;
}
