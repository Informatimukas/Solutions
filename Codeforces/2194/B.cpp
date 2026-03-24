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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n + 1);
        vector<ll> L(n + 2, 0ll), R(n + 2, 0ll);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            L[i] = L[i - 1] + a[i] / x * y;
        }
        ll res = 0;
        for (int i = n; i >= 1; i--) {
            R[i] = R[i + 1] + a[i] / x * y;
            res = max(res, a[i] + L[i - 1] + R[i + 1]);
        }
        cout << res << "\n";
    }
    return 0;
}
