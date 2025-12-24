#include <bits/stdc++.h>
using namespace std;

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
        int res = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i)
                res += abs(a[i - 1] - a[i]);
        }
        int mx = abs(a[0] - a[1]);
        mx = max(mx, abs(a[n - 2] - a[n - 1]));
        for (int i = 1; i + 1 < n; i++)
            mx = max(mx, -abs(a[i - 1] - a[i + 1]) + abs(a[i - 1] - a[i]) +
                abs(a[i] - a[i + 1]));
        cout << res - mx << "\n";
    }
    return 0;
}
