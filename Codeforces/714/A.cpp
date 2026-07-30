#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll L1, R1, L2, R2, x;
    cin >> L1 >> R1 >> L2 >> R2 >> x;
    ll lef = max(L1, L2), rig = min(R1, R2);
    ll res = 0;
    if (lef <= rig) {
        res = rig - lef + 1;
        if (lef <= x && x <= rig)
            res--;
    }
    cout << res << "\n";
    return 0;
}
