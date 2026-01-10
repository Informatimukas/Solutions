#include <bits/stdc++.h>
using namespace std;

vector<int> getRes(const vector<int>& a, int k) {
    vector taken(a.size(), false);
    vector<int> res;
    for (int i = 0; i < a.size(); i++)
        if (!taken[i]) {
            for (int j = a[i]; j <= k; j += a[i]) {
                auto it = ranges::lower_bound(a, j);
                if (it != a.end() && *it == j)
                    taken[distance(a.begin(), it)] = true;
                else return {};
            }
            res.push_back(a[i]);
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        a.erase(ranges::unique(a).begin(), a.end());
        auto res = getRes(a, k);
        if (res.empty())
            cout << "-1\n";
        else {
            cout << res.size() << "\n";
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
        }
    }
    return 0;
}
