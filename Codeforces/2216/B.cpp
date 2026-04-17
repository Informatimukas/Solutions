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
        ll t, h, u;
        cin >> t >> h >> u;
        ll res = 3 * (h + u);
        ll tk = min(t, u);
        res += tk;
        t -= tk;
        tk = min(t, 2 * h);
        res += 2 * tk;
        t -= tk;
        if (t > 0)
            res += 2 * t + 1;
        cout << res << "\n";
    }
    return 0;
}
