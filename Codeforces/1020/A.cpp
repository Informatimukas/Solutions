#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    while (k--) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb) {
            cout << abs(fa - fb) << "\n";
            continue;
        }
        int res = abs(ta - tb) + abs(fa - fb);
        int lef = max(min(fa, fb), a), rig = min(max(fa, fb), b);
        if (lef > rig)
            res += 2 * (lef - rig);
        cout << res << "\n";
    }
    return 0;
}
