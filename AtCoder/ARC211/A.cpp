#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll tot = 0;
        vector<int> cnt(10);
        for (int i = 1; i < 10; i++) {
            cin >> cnt[i];
            tot += cnt[i];
        }
        int res = 0;
        if (cnt[5] > tot - cnt[5])
            res = cnt[5] - 1 - (tot - cnt[5]);
        for (int i = 1; i < 5; i++)
            if (cnt[i] > 0 && cnt[10 - i] > 0 && cnt[i] + cnt[10 - i] == tot)
                res = max(res, 1);
        cout << res << "\n";
    }
    return 0;
}
