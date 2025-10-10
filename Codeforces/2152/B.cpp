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
        ll n, r1, c1, r2, c2;
        cin >> n >> r1 >> c1 >> r2 >> c2;
        ll lef = 1, rig = n;
        while (lef <= rig) {
            ll mid = (lef + rig) / 2;
            ll lefr = r2 - mid, rigr = r2 + mid;
            ll lefc = c2 - mid, rigc = c2 + mid;
            bool ok = lefr > 0 && (r1 < lefr || abs(lefr - r1) < mid) ||
                lefc > 0 && (c1 < lefc || abs(lefc - c1) < mid) ||
                    rigr < n && (r1 > rigr || abs(rigr - r1) < mid) ||
                        rigc < n && (c1 > rigc || abs(rigc - c1) < mid);
            if (ok)
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
