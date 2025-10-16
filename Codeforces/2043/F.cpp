#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Maxv = 51;
constexpr int Maxm = 64;
constexpr int Inf = 1000000000;
constexpr int mod = 998244353;

ii Better(const ii &a, const ii &b) {
    if (a.first != b.first)
        return a.first < b.first ? a : b;
    return {a.first, (a.second + b.second) % mod};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector cnt(n + 1, array<int, Maxv>());
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        int a;
        cin >> a;
        cnt[i][a]++;
    }
    while (q--) {
        vector dp(Maxm, ii{Inf, 0});
        int l, r;
        cin >> l >> r;
        for (int i = 0; i < Maxv; i++) {
            int c = cnt[r][i] - cnt[l - 1][i];
            if (c == 0)
                continue;
            vector ndp = dp;
            ndp[i] = Better(ndp[i], {1, c});
            if (c >= 2)
                ndp[0] = Better(ndp[0], {2, static_cast<ll>(c) * (c - 1) / 2 % mod});
            for (int j = 0; j < Maxm; j++) {
                int nj = (j ^ i);
                ndp[nj] = Better(ndp[nj],
                    {dp[j].first + 1, static_cast<ll>(dp[j].second) * c % mod});
            }
            dp = std::move(ndp);
        }
        if (dp[0].first >= Inf)
            cout << "-1\n";
        else cout << r - l + 1 - dp[0].first << " " << dp[0].second << "\n";
    }
    return 0;
}
