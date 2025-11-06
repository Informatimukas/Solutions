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
        int n, m;
        cin >> n >> m;
        multiset<int> swords;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            swords.insert(a);
        }
        vector<int> b(m), c(m);
        multiset<ii> good;
        vector<int> bad;
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < m; i++) {
            cin >> c[i];
            if (c[i] > 0)
                good.insert({b[i], c[i]});
            else bad.push_back(b[i]);
        }
        int res = 0;
        for (auto it = swords.begin(); it != swords.end(); ) {
            auto it2 = good.lower_bound({*it + 1, 0});
            if (it2 != good.begin()) {
                res++;
                --it2;
                if (it2->second <= *it) {
                    good.erase(it2);
                    continue;
                }
                swords.insert(it2->second);
                good.erase(it2);
                swords.erase(it++);
                continue;
            }
            ++it;
        }
        auto it = swords.begin();
        ranges::sort(bad);
        for (int i = 0; i < bad.size(); i++) {
            while (it != swords.end() && *it < bad[i])
                ++it;
            if (it == swords.end())
                break;
            res++;
            swords.erase(it++);
        }
        cout << res << "\n";
    }
    return 0;
}
