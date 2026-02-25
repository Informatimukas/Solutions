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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(m);
        for (auto& x : b)
            cin >> x;
        ranges::sort(b);
        set<int> deleted;
        deque<ii> L, R;
        for (int i = 0; i < a.size(); i++) {
            int ind = distance(b.begin(), ranges::upper_bound(b, a[i]));
            if (ind < b.size())
                R.emplace_back(b[ind] - a[i], i);
            if (ind > 0)
                L.emplace_back(b[ind - 1] - a[i], i);
        }
        ranges::sort(L);
        ranges::sort(R);
        int cur = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            cur += s[i] == 'R' ? 1 : -1;
            while (!L.empty() && cur <= L.back().first) {
                deleted.insert(L.back().second);
                L.pop_back();
            }
            while (!R.empty() && cur >= R.front().first) {
                deleted.insert(R.front().second);
                R.pop_front();
            }
            cout << n - deleted.size() << (i + 1 < s.length() ? ' ' : '\n');
        }
    }
    return 0;
}
