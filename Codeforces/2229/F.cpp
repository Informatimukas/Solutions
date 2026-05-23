#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 18;

void Solve(int lvl, int n, int r, int mask1, int mask2, int mask3, int st1, int st2, int st3,
    vector<vector<ll>>& dp, const vector<ll>& sum) {
    if (st1 > 0 || st2 > 0 || st3 > 0)
        return;
    if (lvl >= n) {
        dp[r][mask1] = max(dp[r][mask1], min(sum[mask2], dp[r - 1][mask3]));
        return;
    }
    Solve(lvl + 1, n, r, mask1, mask2, mask3, st1, st2, st3 + 1, dp, sum);
    if (mask2)
        Solve(lvl + 1, n, r, mask1 | 1 << lvl, mask2, mask3 | 1 << lvl, st1 + 1, st2, st3, dp, sum);
    Solve(lvl + 1, n, r, mask1 | 1 << lvl, mask2 | 1 << lvl, mask3, st1 + 1, st2 + 1, st3, dp, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        if (n == k) {
            cout << a[n - 1] << "\n";
            continue;
        }
        if (n == k + 1) {
            cout << a[0] + a[n - 1] << "\n";
            continue;
        }
        if (k == 1) {
            cout << accumulate(a.begin(), a.end(), 0ll) << "\n";
            continue;
        }
        int mx = (k + 1) / 2;
        n--;
        vector dp(mx + 1, vector(1 << n, 0ll));
        vector sum(1 << n, 0ll);
        for (int i = 1; i < 1 << n; i++) {
            int j = __builtin_popcount((i & -i) - 1);
            sum[i] = sum[i ^ (1 << j)] + a[j];
            dp[1][i] = sum[i];
        }
        for (int i = 2; i <= mx; i++)
            Solve(0, n, i, 0, 0, 0, k - i - n, i - 1 - n, i - n, dp, sum);
        ll res = 0;
        int all = (1 << n) - 1;
        for (int j = 0; j < 1 << n; j++)
            res = max(res, min(dp[mx][j], dp[k - mx][all ^ j]));
        res += a[n];
        cout << res << "\n";
    }
    return 0;
}
