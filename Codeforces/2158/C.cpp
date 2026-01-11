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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n + 1), b(n + 1);
        vector<ll> L(n + 2), R(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        L[0] = 0;
        for (int i = 1; i <= n; i++)
            L[i] = max(0ll, L[i - 1] + a[i]);
        R[n + 1] = 0;
        for (int i = n; i >= 1; i--)
            R[i] = max(0ll, R[i + 1] + a[i]);
        ll res = -1000000007;
        for (int i = 1; i <= n; i++) {
            ll cand = L[i - 1] + a[i] + R[i + 1];
            if (k % 2)
                cand += b[i];
            res = max(res, cand);
        }
        cout << res << "\n";
    }
    return 0;
}
