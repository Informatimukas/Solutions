#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    b = a;
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    int m;
    cin >> m;
    while (m--) {
        int typ, l, r;
        cin >> typ >> l >> r;
        ll res = typ == 1 ? a[r] - a[l - 1] : b[r] - b[l - 1];
        cout << res << "\n";
    }
    return 0;
}
