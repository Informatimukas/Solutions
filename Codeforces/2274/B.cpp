#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 9000000000000000000ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll mn = 0, mx = 0;
        int n;
        cin >> n;
        ll res = -Inf;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            res = max({res, a - mn, a + mx, a});
            auto nmn = min({a, a + mn, a + 2 * mn});
            auto nmx = max({a, a + mx, a + 2 * mx});
            mn = nmn;
            mx = nmx;
        }
        cout << res << "\n";
    }
    return 0;
}