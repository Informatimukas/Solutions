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
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        ll mx = 0;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] > a[i + 1])
                mx = max(mx, a[i] - a[i + 1]);
        bool ok = true;
        for (int i = 0; i + 1 < n; i++)
            if (a[i] > a[i + 1]) {
                a[i + 1] += mx;
                if (a[i] > a[i + 1]) {
                    ok = false;
                    break;
                }
            }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
