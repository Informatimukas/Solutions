#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 4000000000000000000ll;
constexpr int sInf = 2000000000;

ll Value(const vector<int>& a, const vector<int>& inds) {
    int mn = sInf, mx = -sInf;
    for (auto& x : inds) {
        mn = min(mn, a[x]);
        mx = max(mx, a[x]);
    }
    return mx - mn;
}

ll Solve(int lef, int rig, const vector<int>& a) {
    vector dp(rig + 2, Inf);
    dp[lef] = 0;
    for (int i = lef; i <= rig; i++) {
        if (i + 2 <= rig + 1)
            dp[i + 2] = min(dp[i + 2], dp[i] + Value(a, {i, i + 1}));
        if (i + 3 <= rig + 1)
            dp[i + 3] = min(dp[i + 3], dp[i] + Value(a, {i, i + 1, i + 2}));
    }
    return dp[rig + 1];
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ll res = min({Solve(0, n - 1, a),
                        Value(a, {n - 1, 0}) + Solve(1, n - 2, a),
                        Value(a, {n - 2, n - 1, 0}) + Solve(1, n - 3, a),
                        Value(a, {n - 1, 0, 1}) + Solve(2, n - 2, a)});
        cout << res << "\n";
    }
    return 0;
}
