#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<int> q(n);
        vector<int> r(n);
        for (auto& x : q)
            cin >> x;
        for (auto& x : r)
            cin >> x;
        ranges::sort(q, greater());
        ranges::sort(r);
        int res = 0, pnt = 0;
        for (auto& x : r) {
            while (pnt < q.size() && static_cast<ll>(x + 1) * q[pnt] + x > k)
                pnt++;
            if (pnt < q.size()) {
                pnt++;
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}