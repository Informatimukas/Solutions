#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll res = 0;
        while (n > 0) {
            ll val = 1;
            int x = 0;
            while (val * 3 <= n) {
                val *= 3;
                x++;
            }
            res += 3ll * val + x * val / 3;
            n -= val;
        }
        cout << res << "\n";
    }
    return 0;
}