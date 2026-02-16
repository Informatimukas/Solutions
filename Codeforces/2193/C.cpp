#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n)
                a[i] = max(a[i], a[i + 1]);
            a[i] = max(a[i], b[i]);
        }
        for (int i = 1; i < n; i++)
            a[i] += a[i - 1];
        while (q--) {
            int l, r;
            cin >> l >> r;
            int res = a[r - 1];
            if (l > 1)
                res -= a[l - 2];
            cout << res << (q ? ' ' : '\n');
        }
    }
    return 0;
}
