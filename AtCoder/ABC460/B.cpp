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
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (d2 <= (r1 + r2) * (r1 + r2) && d2 >= (r1 - r2) * (r1 - r2))
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
