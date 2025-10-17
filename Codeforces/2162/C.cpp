#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        int z = 0;
        while (1ll << (z + 1) <= a)
            z++;
        if (1ll << (z + 1) <= b) {
            cout << "-1\n";
            continue;
        }
        ll val = (1ll << (z + 1)) - 1ll;
        vector<ll> res;
        if (val != a)
            res.push_back(a ^ val);
        if (val != b)
            res.push_back(val ^ b);
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? " " : "\n");
    }
    return 0;
}