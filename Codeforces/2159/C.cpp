#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

int Solve(const vector<int>& a) {
    vector neigh(a.size(), set<int>());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= static_cast<int>(a.size()))
            return 0;
        if (a[i] != -1) {
            neigh[a[i]].insert(i);
            neigh[i].insert(a[i]);
        }
    }
    int rem = 0;
    for (int i = 1; i < a.size(); i++) {
        if (neigh[i].size() > 1)
            return 0;
        if (neigh[i].empty())
            rem++;
    }
    vector<int> dp(rem + 1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); i++) {
        dp[i] = 2 * dp[i - 1] % mod;
        if (i > 1)
            dp[i] = (dp[i] + static_cast<ll>(dp[i - 2]) * (i - 1)) % mod;
    }
    int res = 0;
    if (neigh[a.size() - 1].empty()) {
        res = dp[rem - 1];
        if (rem > 1)
            res = (res + static_cast<ll>(dp[rem - 2]) * (rem - 1)) % mod;
    } else res = dp[rem];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (auto& x : a)
            cin >> x;
        cout << Solve(a) << "\n";
    }
    return 0;
}
