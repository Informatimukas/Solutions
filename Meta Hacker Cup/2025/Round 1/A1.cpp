#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i)
                res = max(res, abs(a[i] - a[i - 1]));
        }
        cout << "Case #" << tc << ": " << res << "\n";
    }
    return 0;
}