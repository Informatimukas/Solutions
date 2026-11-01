#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<ii> seq(q);
        for (auto& [l, r] : seq)
            cin >> l >> r;
        ranges::sort(seq, [](auto&& x, auto&& y) {
            if (x.first != y.first)
                return x.first < y.first;
            return x.second > y.second;
        });
        vector<ii> tmp;
        for (auto& p : seq)
            if (tmp.empty() || tmp.back().second < p.second)
                tmp.push_back(p);
        seq = tmp;
        int res = 0;
        int l = 0, r = seq.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int my = Ask(seq[mid].first, seq[mid].second);
            int bet = Ask(seq[mid].first, n);
            res = max(res, my);
            if (my < bet)
                l = mid + 1;
            else r = mid - 1;
        }
        cout << "! " << res << endl;
    }
    return 0;
}
