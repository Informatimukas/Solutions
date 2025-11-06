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
        vector<int> a(n), mx(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx[i] = a[i];
            if (i)
                mx[i] = max(mx[i - 1], a[i]);
        }
        ll res = 0;
        for (int i = 0; i < n; i += 2) {
            int mn = 1000000007;
            if (i) mn = min(mn, mx[i - 1]);
            if (i + 1 < n) mn = min(mn, mx[i + 1]);
            if (a[i] >= mn)
                res += a[i] - mn + 1;
        }
        cout << res << "\n";
    }
    return 0;
}
