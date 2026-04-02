#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    array<ll, 2> dp{};
    ll res = 0;
    for (int i = 0; i < n; i++) {
        array<ll, 2> ndp{};
        if (i) {
            if (a[i - 1] >= a[i])
                ndp[0] += dp[0];
            else ndp[1] += dp[0];
            if (a[i - 1] <= a[i])
                ndp[1] += dp[1];
        }
        ndp[0]++;
        res += ndp[0] + ndp[1];
        dp = std::move(ndp);
    }
    cout << res << "\n";
    return 0;
}
