#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l, x, y;
    cin >> n >> m >> l >> x >> y;
    vector<ii> st(n);
    for (auto& [s, t] : st)
        cin >> s >> t;
    ranges::sort(st);
    vector<ii> pind(m);
    for (int i = 0; i < m; i++) {
        cin >> pind[i].first;
        pind[i].second = i;
    }
    ranges::sort(pind);
    vector<ld> res(m);
    ld best = 1e30l;
    int pnt = 0;
    for (auto& [p, ind] : pind) {
        while (pnt < n && st[pnt].first <= p) {
            best = min(best, static_cast<ld>(st[pnt].second - st[pnt].first) / x +
                static_cast<ld>(l - st[pnt].second) / y);
            pnt++;
        }
        ld cur = static_cast<ld>(l - p) / y;
        res[ind] = min(best, cur);
    }
    for (auto& x : res)
        cout << fixed << setprecision(10) << x << "\n";
    return 0;
}