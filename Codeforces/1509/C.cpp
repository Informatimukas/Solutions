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
    ranges::sort(a);
    vector dp(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int l = 1; l < n; l++)
        for (int i = 0, j = i + l; j < n; i++, j++)
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + a[j] - a[i];
    cout << dp[0][n - 1] << "\n";
    return 0;
}
