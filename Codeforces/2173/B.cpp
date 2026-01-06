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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        ll mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            ll nmn = min(mn - a[i], b[i] - mx);
            ll nmx = max(mx - a[i], b[i] - mn);
            mn = nmn;
            mx = nmx;
        }
        cout << mx << "\n";
    }
    return 0;
}
