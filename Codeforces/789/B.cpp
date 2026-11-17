#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    set<ll> forb;
    for (int i = 0; i < m; i++) {
        ll num;
        cin >> num;
        forb.insert(num);
    }
    int res = 0;
    for (int i = 0; i < 60 && abs(b1) <= l; i++) {
        res += !forb.contains(b1);
        b1 *= q;
    }
    if (abs(b1) <= l && (!forb.contains(b1) || !forb.contains(b1 * q)))
        cout << "inf\n";
    else cout << res << "\n";
    return 0;
}
