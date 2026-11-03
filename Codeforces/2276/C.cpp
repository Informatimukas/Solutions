#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        vector<int> has(k);
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = (a[i] + a[i - 1]) % k;
            res += has[a[i]];
            if (i - k >= 0)
                ++has[a[i - k]];
        }
        cout << res << "\n";
    }
    return 0;
}
