#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Inf = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> has(n + 1);
        vector<int> un;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            has[x].push_back(y);
            un.push_back(y);
        }
        ranges::sort(un);
        un.erase(ranges::unique(un).begin(), un.end());
        vector<ii> L(n + 1);
        ii cur = {Inf, -Inf};
        for (int i = 0; i <= n; i++) {
            if (!has[i].empty()) {
                ranges::sort(has[i]);
                cur.first = min(cur.first, has[i][0]);
                cur.second = max(cur.second, has[i].back());
            }
            L[i] = cur;
        }
        cur = {Inf, -Inf};
        vector<ii> R(n + 1);
        for (int i = n; i >= 0; i--) {
            if (!has[i].empty()) {
                cur.first = min(cur.first, has[i][0]);
                cur.second = max(cur.second, has[i].back());
            }
            R[i] = cur;
        }
        ll res = 0;
        for (int i = 0; i < n; i++)
            if (!has[i].empty() && L[i].first != Inf && R[i + 1].first != Inf) {
                int mn = max(L[i].first, R[i + 1].first);
                int mx = min(L[i].second, R[i + 1].second);
                if (mn < mx)
                    res += ranges::lower_bound(un, mx) - ranges::lower_bound(un, mn);
            }
        cout << res << "\n";
    }
    return 0;
}
