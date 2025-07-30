#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        if (n % 2) {
            cout << l << "\n";
            continue;
        }
        ll pw = 1;
        while (pw <= l)
            pw *= 2;
        if (pw > r || n <= 2) {
            cout << -1 << "\n";
            continue;
        }
        cout << (k > n - 2 ? pw : l) << "\n";
    }
    return 0;
}