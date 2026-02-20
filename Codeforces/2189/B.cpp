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
        ll x;
        cin >> n >> x;
        ll mx = 0;
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            x -= a * (b - 1);
            mx = max(mx, a * b - c);
        }
        if (x <= 0)
            cout << "0\n";
        else if (mx <= 0)
            cout << "-1\n";
        else cout << (x + mx - 1) / mx << "\n";
    }
    return 0;
}
