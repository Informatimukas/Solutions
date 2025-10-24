#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector delt(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (a / 4 >= 1) {
                delt[1]++;
                delt[a / 4 + 1]--;
            }
            if (a % 3 == 0) {
                delt[a / 3]++;
                delt[a / 3 + 1]--;
            }
            if (a % 2 == 0) {
                delt[a / 2]++;
                delt[a / 2 + 1]--;
            }
            delt[a]++;
            delt[a + 1]--;
        }
        int res = 1, cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += delt[i];
            if (cur >= n - k)
                res = i;
        }
        cout << res << "\n";
    }
    return 0;
}