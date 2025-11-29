#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<ii> seq(m);
        for (auto& [l, r] : seq)
            cin >> l >> r;
        ranges::sort(seq, [](auto&& x, auto&& y) {
            return x.second < y.second;
        });
        map<int, int> M;
        int tot = 0;
        M.emplace(1, 2);
        tot = 2;
        int pnt = 0;
        for (int i = 2; i <= n; i++) {
            int ways = tot;
            M[i] = ways;
            tot = (tot + ways) % mod;
            while (pnt < seq.size() && seq[pnt].second == i) {
                while (M.begin()->first <= seq[pnt].first) {
                    tot = (tot - M.begin()->second + mod) % mod;
                    M.erase(M.begin());
                }
                pnt++;
            }
        }
        cout << tot << "\n";
    }
    return 0;
}
