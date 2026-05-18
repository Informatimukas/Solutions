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
        int n;
        cin >> n;
        vector<ll> c(n);
        for (auto& x : c)
            cin >> x;
        ll pnt = 0;
        while (pnt < n && c[pnt] == 1)
            pnt++;
        ll res = 0;
        if (c[n - 1] >= 2)
            res = max(res, c[n - 1] + min(pnt, c[n - 1] / 2));
        if (pnt < n) {
            ll sum = 0;
            ll allow = 0;
            for (int i = pnt; i < n; i++) {
                sum += c[i];
                allow += (c[i] - 2) / 2;
            }
            res = max(res, sum + min(pnt, allow));
        }
        if (res < 3)
            res = 0;
        cout << res << "\n";
    }
    return 0;
}
