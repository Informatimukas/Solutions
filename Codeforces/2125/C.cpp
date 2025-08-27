#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const vector smallPrimes = {2, 3, 5, 7};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll l, r;
        cin >> l >> r;
        ll res = 0;
        for (int i = 0; i < 1 << smallPrimes.size(); i++) {
            int x = 1, delt = 1;
            for (int j = 0; j < smallPrimes.size(); j++)
                if (i & 1 << j) {
                    x *= smallPrimes[j];
                    delt = -delt;
                }
            res += delt * (r / x - (l - 1) / x);
        }
        cout << res << "\n";
    }
    return 0;
}
