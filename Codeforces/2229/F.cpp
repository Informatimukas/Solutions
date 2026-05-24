#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 18;

struct State {
    int lvl, n, r, mask1, mask2, st1, st2, st3;
    vector<vector<ll>> dp;
    vector<ll> sum;
};

State S;

void Solve() {
    if (S.st1 > 0 || S.st2 > 0 || S.st3 > 0)
        return;
    if (S.lvl >= S.n) {
        S.dp[S.r][S.mask1] = max(S.dp[S.r][S.mask1], min(S.sum[S.mask2],
            S.dp[S.r - 1][S.mask1 ^ S.mask2]));
        return;
    }
    ++S.lvl;
    ++S.st3;
    Solve();
    --S.st3;
    --S.lvl;
    if (S.mask2) {
        S.mask1 ^= 1 << S.lvl;
        ++S.st1;
        ++S.lvl;
        Solve();
        --S.lvl;
        --S.st1;
        S.mask1 ^= 1 << S.lvl;
    }
    S.mask1 ^= 1 << S.lvl;
    S.mask2 ^= 1 << S.lvl;
    ++S.st1;
    ++S.st2;
    ++S.lvl;
    Solve();
    --S.lvl;
    --S.st2;
    --S.st1;
    S.mask2 ^= 1 << S.lvl;
    S.mask1 ^= 1 << S.lvl;
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
        S.dp = vector(mx + 1, vector(1 << n, 0ll));
        S.sum = vector(1 << n, 0ll);
        for (int i = 1; i < 1 << n; i++) {
            int j = __builtin_popcount((i & -i) - 1);
            S.sum[i] = S.sum[i ^ (1 << j)] + a[j];
            S.dp[1][i] = S.sum[i];
        }
        S.n = n;
        for (int i = 2; i <= mx; i++) {
            S.lvl = 0;
            S.r = i;
            S.mask1 = S.mask2 = 0;
            S.st1 = k - i - n;
            S.st2 = i - 1 - n;
            S.st3 = i - n;
            Solve();
        }
        ll res = 0;
        int all = (1 << n) - 1;
        for (int j = 0; j < 1 << n; j++)
            res = max(res, min(S.dp[mx][j], S.dp[k - mx][all ^ j]));
        res += a[n];
        cout << res << "\n";
    }
    return 0;
}
