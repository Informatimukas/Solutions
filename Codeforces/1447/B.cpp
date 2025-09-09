#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int mn = 100, od = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                if (a < 0) {
                    od++;
                    a = -a;
                }
                res += a;
                mn = min(mn, a);
            }
        if (od % 2) res -= 2 * mn;
        cout << res << "\n";
    }
    return 0;
}