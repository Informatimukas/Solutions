#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n), lef(n), rig(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        lef[i] = p[i];
        if (i)
            lef[i] = __gcd(lef[i - 1], lef[i]);
    }
    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
        rig[i] = p[i];
        if (i + 1 < n)
            rig[i] = __gcd(rig[i + 1], rig[i]);
        res += min(lef[i], rig[i]);
    }
    res -= rig[0];
    cout << res << "\n";
    return 0;
}