#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector delt(m + 2, 0);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            delt[1]++;
            delt[a + 1]--;
            if (a % 2 == 0) {
                delt[a / 2]++;
                delt[a / 2 + 1]--;
            }
        }
        int res = 0, cur = 0;
        for (int i = 1; i <= m; i++) {
            cur += delt[i];
            res = max(res, cur);
        }
        cout << res << "\n";
    }
    return 0;
}
