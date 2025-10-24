#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

constexpr int Inf = 2000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector my(n, vector<ii>());
        set<ii> best;
        for (int i = 0; i < a.size(); i++) {
            if (best.size() > 3)
                best.erase(prev(best.end()));
            for (auto& el : best)
                my[i].emplace_back(a[i] - el.first, el.second);
            best.emplace(a[i], i);
        }
        best.clear();
        vector<iii> mx;
        vector res(n, -Inf);
        for (int i = a.size() - 1; i >= 0; i--) {
            if (best.size() > 3)
                best.erase(best.begin());
            for (auto& el : best)
                my[i].emplace_back(el.first - a[i], el.second);
            best.emplace(a[i], i);
            my[i].emplace_back(-Inf, i);
            ranges::sort(my[i], {}, &ii::second);
            int cand = Inf;
            for (int c = 0; c < my[i].size(); c++)
                if (my[i][c].second != i) {
                    int cur = -Inf;
                    for (int d = 0; d < my[i].size(); d++)
                        if (d != c && my[i][d].second != i)
                            cur = max(cur, my[i][d].first);
                    cand = min(cand, cur);
                }
            int nxt = 0;
            for (auto& x : my[i] | views::values) {
                if (nxt < x)
                    mx.emplace_back(cand, ii{nxt, x - 1});
                nxt = x + 1;
            }
            if (nxt < n)
                mx.emplace_back(cand, ii{nxt, n - 1});
            for (int b = 0; b < my[i].size(); b++)
                if (my[i][b].second != i) {
                    int cand = Inf;
                    for (int c = 0; c < my[i].size(); c++)
                        if (b != c && my[i][c].second != i) {
                            int cur = -Inf;
                            for (int d = 0; d < my[i].size(); d++)
                                if (d != c && d != b && my[i][d].second != i)
                                    cur = max(cur, my[i][d].first);
                            cand = min(cand, cur);
                        }
                    res[my[i][b].second] = max(res[my[i][b].second], cand);
                }
        }
        ranges::sort(mx, greater());
        set<int> S;
        for (int i = 0; i < n; i++)
            S.insert(i);
        for (auto& [value, p] : mx) {
            auto it = S.lower_bound(p.first);
            while (it != S.end() && *it <= p.second) {
                res[*it] = max(res[*it], value);
                S.erase(it++);
            }
        }
        cout << *ranges::min_element(res) << "\n";
    }
    return 0;
}