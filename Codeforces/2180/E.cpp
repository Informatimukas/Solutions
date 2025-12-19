#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(int lvl, ll lef, ll rig) {
    if (lvl < 0)
        return 1;
    ll cur = 1ll << lvl;
    if (cur <= lef)
        return Solve(lvl - 1, lef - cur, rig - cur);
    if (lef & 1ll << lvl)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll l, r;
        cin >> l >> r;
        ll res = 1;
        while (true) {
            if ((r - l) % 2 == 0)
                break;
            if (l % 2 == 0)
                res *= 2;
            l /= 2;
            r /= 2;
        }
        cout << res - 1 << "\n";
    }
    return 0;
}
