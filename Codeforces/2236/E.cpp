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
        for (auto& x : a)
            cin >> x;
        vector has(n + 1, vector<bool>(n + 1));
        for (int i = 0; i < n; i++) {
            int mn = a[i], mx = a[i];
            vector tk(n + 1, false);
            for (int j = i; j < n; j++) {
                if (tk[a[j]])
                    break;
                tk[a[j]] = true;
                mn = min(mn, a[j]);
                mx = max(mx, a[j]);
                if (mx - mn == j - i)
                    has[mn][mx] = true;
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j += 2) {
                int m = (i + j) / 2;
                if (has[i][m] && has[m + 1][j])
                    res = max(res, m + 1 - i);
            }
        cout << res << "\n";
    }
    return 0;
}
