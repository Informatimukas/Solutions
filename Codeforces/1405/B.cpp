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
        ll res = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (x < 0) {
                ll tk = min(-x, cur);
                cur -= tk;
                x += tk;
                res -= x;
            } else cur += x;
        }
        cout << res << "\n";
    }
    return 0;
}
