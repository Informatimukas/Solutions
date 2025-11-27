#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x;
        ll m;
        cin >> x >> m;
        ll res = 0;
        for (int i = 1; i <= m && i <= x; i++)
            if ((i ^ x) % i == 0)
                res++;
        for (int i = 2; i < 2 * x; i++)
            if (((i * x) ^ x) <= m)
                res++;
        ll k = m / x;
        if (k >= 2 * x)
            res += k - 2 * x + 1;
        cout << res << "\n";
    }
    return 0;
}