#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, h, k;
        cin >> n >> h >> k;
        vector<ll> a(n);
        ll sum = 0;
        for (auto& x : a) {
            cin >> x;
            sum += x;
        }
        ll tims = (h - 1) / sum;
        ll res = tims * (n + k);
        h -= sum * tims;
        int lef = 1, rig = n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            ll mn = Inf, mx = -Inf;
            ll tot = 0;
            for (int i = 0; i < mid; i++) {
                mn = min(mn, a[i]);
                tot += a[i];
            }
            for (int i = mid; i < n; i++)
                mx = max(mx, a[i]);
            if (mx > mn)
                tot += mx - mn;
            if (tot >= h)
                rig = mid - 1;
            else lef = mid + 1;
        }
        res += lef;
        cout << res << "\n";
    }
    return 0;
}
