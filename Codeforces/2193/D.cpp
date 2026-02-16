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
        ranges::sort(a);
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (i)
                b[i] += b[i - 1];
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            auto ind = distance(b.begin(), ranges::upper_bound(b, n - i));
            res = max(res, a[i] * ind);
        }
        cout << res << "\n";
    }
    return 0;
}
