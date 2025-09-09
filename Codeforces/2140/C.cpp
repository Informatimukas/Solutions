#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        ll sum = 0, ev = -Inf, od = -Inf;
        ll evind = -Inf, odind = -Inf;
        ll mx = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (i % 2) {
                sum += a[i];
                mx = max(mx, -2 * a[i] + i + ev);
                od = max(od, -2 * a[i] - i);
                mx = max(mx, i + odind);
                odind = max(odind, -i);
            } else {
                sum -= a[i];
                mx = max(mx, 2 * a[i] + i + od);
                ev = max(ev, 2 * a[i] - i);
                mx = max(mx, i + evind);
                evind = max(evind, -i);
            }
        }
        cout << sum + mx << "\n";
    }
    return 0;
}
