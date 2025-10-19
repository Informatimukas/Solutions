#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        map<int, ii> mn;
        int best = 0, bl, br, ba;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            mn[x] = min(mn[x], {2 * cnt[x] - (i - 1), i - 1});
            int st = 2 * (++cnt[x]) - i;
            int cand = st - mn[x].first;
            if (cand > best) {
                best = cand;
                bl = mn[x].second + 1;
                br = i;
                ba = x;
            }
            mn[x] = min(mn[x], {st, i});
        }
        cout << ba << " " << bl << " " << br << "\n";
    }
    return 0;
}
