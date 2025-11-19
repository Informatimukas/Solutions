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
        ranges::sort(a);
        ll res = 0, sum = a[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            sum += a[i];
            res = max(res, a[n - 1] - sum / (i + 2));
        }
        sum = a[0];
        for (int i = n - 1; i > 0; i--) {
            sum += a[i];
            res = max(res, sum / (n - i + 1) - a[0]);
        }
        cout << res << "\n";
    }
    return 0;
}
