#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;
constexpr int nil = 100 * 100;
constexpr int Maxm = 2 * nil + 5;

void Add(vector<vector<int>>& dp, int a, int &dif) {
    vector ndp(dp.size(), vector(Maxm, 0));
    for (int i = 0; i < dp.size(); i++) {
        int B = i - dif;
        for (int j = 0; j < dp[i].size(); j++) if (dp[i][j]) {
            if (B > 0)
                ndp[i][j] = (ndp[i][j] + static_cast<ll>(B) * dp[i][j]) % mod;
            if (a <= 100)
                ndp[i + 1][j - a] = (ndp[i + 1][j - a] + dp[i][j]) % mod;
        }
    }
    dif++;
    dp = std::move(ndp);
}

void Rem(vector<vector<int>>& dp, int a, int &dif) {
    vector ndp(dp.size(), vector(Maxm, 0));
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) if (dp[i][j]) {
            if (i > 0)
                ndp[i - 1][j + a] = (ndp[i - 1][j + a] + static_cast<ll>(i) * dp[i][j]) % mod;
            ndp[i][j] = (ndp[i][j] + dp[i][j]) % mod;
        }
    }
    dif--;
    dp = std::move(ndp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& y : a)
        cin >> y;
    ranges::sort(a);
    vector dp(n + 1, vector(Maxm, 0));
    dp[0][nil] = 1;
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    int i = 0, j = 0, dif = 0;
    while (i < n || j < n) {
        if (i < n && (j >= n || a[i] < b[j])) {
            x -= a[i];
            Add(dp, a[i], dif);
            i++;
        } else {
            x += b[j];
            Rem(dp, b[j], dif);
            j++;
        }
    }
    int res = 0;
    for (int j = nil; j < Maxm; j++)
        if (j - nil <= x)
            res = (res + dp[0][j]) % mod;
    cout << res << "\n";
    return 0;
}
