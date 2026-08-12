#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

constexpr int Inf = 2000000000;

int Count(const vector<iii>& best, set<int> spec, int rem) {
    for (int i = 0; i < best.size() && best[i].first <= rem; i++)
        if (!spec.contains(best[i].second.first)) {
            rem -= best[i].first;
            spec.insert(best[i].second.first);
        }
    return spec.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n + 1);
        vector<iii> best;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            best.push_back({a[i] + i, {i, 0}});
            best.push_back({n + 1 - i + a[i], {i, 1}});
        }
        ranges::sort(best);
        set<int> spec;
        int rem = c;
        bool was = false;
        for (int i = 0; i < best.size() && best[i].first <= rem; i++)
            if (!spec.contains(best[i].second.first)) {
                rem -= best[i].first;
                spec.insert(best[i].second.first);
                if (best[i].second.second == 0)
                    was = true;
            }
        if (was) {
            cout << spec.size() << "\n";
            continue;
        }
        int def = Inf;
        int wth;
        for (auto x : spec) {
            int cand = x - (n + 1 - x);
            if (x + a[x] <= c && cand < def) {
                def = cand;
                wth = x;
            }
        }
        int res = 0;
        if (def < Inf)
            res = max(res, Count(best, {wth}, c - a[wth] - wth));
        def = Inf;
        for (int i = 1; i <= n; i++)
            if (!spec.contains(i)) {
                int cand = i + a[i];
                if (cand < def) {
                    def = cand;
                    wth = i;
                }
            }
        if (def < Inf && def <= c)
            res = max(res, Count(best, {wth}, c - a[wth] - wth));
        cout << res << "\n";
    }
    return 0;
}
