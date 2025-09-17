#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a, greater());
        ll res = 0;
        for (auto& x : a) {
            if (m == 0) break;
            res += static_cast<ll>(x) * m--;
        }
        cout << res << "\n";
    }
    return 0;
}