#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Maxk = 20;

int goodSteps(int a, int b, const vector<array<int, Maxk>>& nxt) {
    if (a >= b)
        return -1;
    int res = 0;
    for (int i = Maxk - 1; i >= 0; i--)
        if (nxt[a][i] < nxt[b][i]) {
            res += 1 << i;
            a = nxt[a][i];
            b = nxt[b][i];
        }
    return res;
}

ii Move(int a, int b, int cnt, const vector<array<int, Maxk>>& nxt) {
    if (cnt % 2) {
        cnt--;
        a = nxt[a][0];
        swap(a, b);
    }
    cnt /= 2;
    for (int j = Maxk - 1; j >= 0; j--)
        if (1 << j <= cnt) {
            a = nxt[a][j];
            b = nxt[b][j];
            cnt -= 1 << j;
        }
    return {a, b};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, z;
        cin >> n >> z;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector nxt(n + 1, array<int, Maxk>());
        for (int j = 0; j < Maxk; j++)
            nxt[n][j] = n;
        for (int i = n - 1; i >= 0; i--) {
            nxt[i][0] = distance(a.begin(), ranges::upper_bound(a, a[i] + z));
            for (int j = 1; j < Maxk; j++)
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
        vector dp(n + 1, vector<ii>(Maxk));
        for (int j = 0; j < Maxk; j++)
            dp[n][j] = {0, n};
        for (int i = n - 1; i >= 0; i--) {
            int mn = min(2 * goodSteps(i, i + 1, nxt),
                2 * goodSteps(i + 1, nxt[i][0], nxt) + 1);
            dp[i][0] = {mn + 1, Move(i, i + 1, mn, nxt).second};
            cout << "dp[" << i << "][0] = " << dp[i][0].first << ", " << dp[i][0].second << endl;
            for (int j = 1; j < Maxk; j++) {
                auto& [steps, ni] = dp[i][j - 1];
                dp[i][j] = {steps + dp[ni][j - 1].first, dp[ni][j - 1].second};
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (r - l + 1 <= 2) {
                cout << r - l + 1 << "\n";
                continue;
            }
            int res = 2;
            int cur = l;
            for (int i = Maxk - 1; i >= 0; i--)
                if (dp[cur][i].second < r) {
                    res += dp[cur][i].first;
                    cur = dp[cur][i].second;
                }
            int lef = 1, rig = dp[cur][0].first;
            while (lef <= rig) {
                int mid = (lef + rig) / 2;
                if (Move(cur, cur + 1, mid, nxt).second <= r)
                    lef = mid + 1;
                else rig = mid - 1;
            }
            res += rig;
            cout << res << "\n";
        }
    }
    return 0;
}