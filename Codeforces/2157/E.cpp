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
        vector cnt(3 * n + 5, 0);
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        int nxt = 1, res = 0, cur = 0;
        for (int i = 1; i < cnt.size(); i++) {
            cur += cnt[i];
            if (cur <= k) {
                cur = 0;
                res = max(res, i - nxt);
                nxt = i + 1;
                continue;
            }
            cur--;
        }
        cout << res << "\n";
    }
    return 0;
}