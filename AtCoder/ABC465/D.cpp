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
        int res = 0;
        while (x != y) {
            if (x > y)
                swap(x, y);
            y /= k;
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}
