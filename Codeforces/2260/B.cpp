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
        ll x, y, k;
        cin >> x >> y >> k;
        ll res = 0;
        for (int i = 0; i <= y && i < k; i++)
            res += (y + i) % (x + i);
        if (y < k)
            res += (k - y - 1) * (y - x);
        cout << res << "\n";
    }
    return 0;
}
