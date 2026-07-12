#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll lef = 0, rig = 1000000000;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            if (mid * (mid + 1) <= n)
                lef = mid + 1;
            else rig = mid - 1;
        }
        ll m = rig;
        ll res = 2 * n - (2 * m + 1);
        if (m * (m + 1) < n)
            res--;
        if (m * (m + 1) + (m + 1) < n)
            res--;
        cout << res << "\n";
    }
    return 0;
}
