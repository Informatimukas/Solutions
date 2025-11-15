#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll lim = 1000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll x, y, k;
        cin >> x >> y >> k;
        if (y == 1) {
            cout << "-1\n";
            continue;
        }
        if (k < y) {
            cout << k << "\n";
            continue;
        }
        k--;
        y--;
        while (x > 0 && k <= lim) {
            ll d = k / y;
            ll nxt = (d + 1) * y;
            ll tims = min(x, (nxt - 1 - k) / d + 1);
            x -= tims;
            k += d * tims;
        }
        k++;
        if (k > lim)
            k = -1;
        cout << k << "\n";
    }
    return 0;
}
