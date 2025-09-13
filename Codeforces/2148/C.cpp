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
        int tim = 0, pos = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            pos = (pos + a - tim) % 2;
            res += a - tim;
            tim = a;
            if (pos != b) {
                res--;
                pos = b;
            }
        }
        res += m - tim;
        cout << res << "\n";
    }
    return 0;
}