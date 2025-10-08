#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector my(n, vector<ii>(n));
    for (int i = 0; i < n; i++) {
        bool was = false;
        for (auto& p : my[i]) {
            cin >> p.second;
            p.second--;
            if (i == p.second) {
                if (was)
                    p.first = n;
                else {
                    p.first = 0;
                    was = true;
                }
            } else p.first = (p.second - i + n) % n;
        }
    }
    vector<vector<int>> res;
    while (true) {
        vector<ii> ans(n);
        bool finish = false;
        for (int i = 0; i < n; i++) {
            auto it = ranges::max_element(my[i]);
            ans[i] = *it;
            if (ans[i].first == 0) {
                finish = true;
                break;
            }
            my[i].erase(it);
        }
        if (finish)
            break;
        for (int i = 0; i < n; i++)
            my[(i + 1) % n].emplace_back(ans[i].first - 1, ans[i].second);
        res.emplace_back(vector<int>());
        ranges::transform(ans, back_inserter(res.back()),
            [](auto&& p) {
                return p.second;
            });
    }
    cout << res.size() << "\n";
    for (auto& x : res)
        for (int i = 0; i < x.size(); i++)
            cout << x[i] + 1 << (i + 1 < x.size() ? ' ' : '\n');
    return 0;
}