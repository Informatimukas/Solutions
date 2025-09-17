#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;

void Add(vector<vector<int>>& dp, int r, int c, int val) {
    for (int i = r; i > 0; i -= i & -i)
        for (int j = c; j > 0; j -= j & -j)
            dp[i][j] = (dp[i][j] + val) % mod;
}

int Get(vector<vector<int>>& dp, int r, int c) {
    int res = 0;
    for (int i = r; i < dp.size(); i += i & -i)
        for (int j = c; j < dp[i].size(); j += j & -j)
            res = (res + dp[i][j]) % mod;
    return res;
}

int main() {
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
        ranges::reverse(a);
        vector dp(n + 1, vector(n + 1, 0));
        Add(dp, n, n, 1);
        for (auto& x : a) {
            int lst = 0;
            vector my(n + 1, 0);
            for (int i = n; i >= x; i--) {
                int got = Get(dp, x, i);
                my[i] = (got - lst + mod) % mod;
                lst = got;
            }
            lst = Get(dp, x, x);
            for (int i = x - 1; i > 0; i--) {
                int got = Get(dp, i, x);
                my[i] = (got - lst + mod) % mod;
                lst = got;
            }
            for (int i = 1; i < x; i++)
                Add(dp, i, x, my[i]);
            for (int i = x; i <= n; i++)
                Add(dp, x, i, my[i]);
        }
        cout << Get(dp, 1, 1) << "\n";
    }
    return 0;
}