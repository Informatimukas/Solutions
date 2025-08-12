#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

optional<ii> Solve(int x, int k, const vector<int>& a) {
    vector sum(a.size(), 0);
    ii best = {1000000000, 0};
    for (int i = 1; i < a.size(); i++) {
        sum[i] = sum[i - 1] + (a[i] >= x? 1: -1);
        if (i >= k)
            best = min(best, {sum[i - k], i - k});
        if (sum[i] >= best.first)
            return ii{best.second + 1, i};
    }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int lef = 1, rig = n;
        int val;
        ii wth;
        while (lef <= rig) {
            int m = lef + rig >> 1;
            auto got = Solve(m, k, a);
            if (got.has_value()) {
                val = m;
                wth = got.value();
                lef = m + 1;
            } else rig = m - 1;
        }
        cout << val << " " << wth.first << " " << wth.second << "\n";
    }
    return 0;
}
