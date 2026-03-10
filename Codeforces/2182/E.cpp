#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        multiset<int> S;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            S.insert(x);
        }
        vector<ii> seq(n);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            k -= y;
            seq[i] = {z - y, x};
        }
        ranges::sort(seq, greater());
        vector<int> rem;
        int res = 0;
        for (auto& [z, x] : seq) {
            auto it = S.lower_bound(x);
            if (it != S.end()) {
                S.erase(it);
                ++res;
            } else rem.push_back(z);
        }
        for (auto x : rem | views::reverse)
            if (x <= k) {
                ++res;
                k -= x;
            }
        cout << res << "\n";
    }
    return 0;
}
