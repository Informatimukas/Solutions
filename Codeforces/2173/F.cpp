#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, ll> Solve(const vector<ll>& sum, int cur, int r, ll x) {
    int res = 0;
    while (sum[r] - sum[cur] >= x) {
        int cnt = distance(sum.begin() + cur,
            lower_bound(sum.begin() + cur + 1, sum.begin() + r, sum[cur] + x));
        int lef = 2, rig = (r - cur) / cnt;
        while (lef <= rig) {
            int m = (lef + rig) / 2;
            if (sum[cur + m * cnt] - sum[cur + (m - 1) * cnt] >= x)
                lef = m + 1;
            else rig = m - 1;
        }
        res += rig;
        cur += rig * cnt;
    }
    return {res, sum[r] - sum[cur]};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<ll> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            sum[i] = sum[i - 1] + a;
        }
        while (q--) {
            int l, r, x;
            cin >> l >> r >> x;
            auto [res, lft] = Solve(sum, l - 1, r, x);
            cout << res << " " << lft << "\n";
        }
    }
    return 0;
}
