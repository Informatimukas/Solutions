#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            bool ok = true;
            for (int j = i - 1; j >= 0; j--)
                if (a[j] * (1ll << (i - 1 - j)) > c) {
                    ok = false;
                    break;
                }
            if (ok) res = i;
            else break;
        }
        cout << n - res << "\n";
    }
    return 0;
}