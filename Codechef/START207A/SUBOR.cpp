#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Maxb = 30;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector seq(Maxb, vector<int>());
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < Maxb; j++)
                if (a & 1 << j)
                    seq[j].push_back(i);
        }
        ll res = static_cast<ll>(n) * (n + 1) / 2;
        for (int i = 1; i < n; i++) {
            vector<ii> my;
            for (int j = 0; j < Maxb; j++) {
                auto ind = distance(seq[j].begin(), ranges::lower_bound(seq[j], i));
                if (ind > 0 && ind < seq[j].size())
                    my.emplace_back(seq[j][ind - 1], seq[j][ind]);
            }
            ranges::sort(my, greater());
            int mn = n;
            int pnt = i - 1;
            for (auto& p : my) {
                res += static_cast<ll>(pnt - p.first) * (mn - i);
                mn = min(mn, p.second);
                pnt = p.first;
            }
            res += static_cast<ll>(pnt + 1) * (mn - i);
        }
        cout << res << "\n";
    }
    return 0;
}
