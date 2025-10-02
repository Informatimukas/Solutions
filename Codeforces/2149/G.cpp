#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> un;
        for (auto& x : a) {
            cin >> x;
            un.push_back(x);
        }
        ranges::sort(un);
        un.erase(ranges::unique(un).begin(), un.end());
        vector seq(un.size(), vector<int>());
        for (int i = 0; i < n; i++) {
            a[i] = distance(un.begin(), ranges::lower_bound(un, a[i]));
            seq[a[i]].push_back(i);
        }
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int nd = (r - l + 1) / 3;
            set<int> S;
            for (int i = 0; i < 100 && S.size() < 2; i++) {
                int val = a[uniform_int_distribution(l, r)(rng)];
                if (ranges::upper_bound(seq[val], r) -
                    ranges::lower_bound(seq[val], l) > nd)
                    S.insert(val);
            }
            if (S.empty()) {
                cout << "-1\n";
                continue;
            }
            vector res(S.begin(), S.end());
            for (int i = 0; i < res.size(); i++)
                cout << un[res[i]] << (i + 1 < res.size() ? ' ' : '\n');
        }
    }
    return 0;
}