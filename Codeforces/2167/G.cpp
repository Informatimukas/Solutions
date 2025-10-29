#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
        vector<int> c(n);
        ll sum = 0;
        for (auto& x : c) {
            cin >> x;
            sum += x;
        }
        ll mx = 0;
        vector<ll> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = c[i];
            for (int j = 0; j < i; j++)
                if (a[j] <= a[i])
                    dp[i] = max(dp[i], dp[j] + c[i]);
            mx = max(mx, dp[i]);
        }
        cout << sum - mx << "\n";
    }
    return 0;
}
