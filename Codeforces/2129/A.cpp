#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<ii, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<iii> seq(n);
        for (int i = 0; i < n; i++) {
            cin >> seq[i].first.first >> seq[i].first.second;
            seq[i].second = i;
        }
        ranges::sort(seq, [](const iii& a, const iii& b) {
            if (a.first.first != b.first.first)
                return a.first.first < b.first.first;
            return a.first.second > b.first.second;
        });
        vector<int> res;
        vector<ii> nw;
        for (int i = 0; i < seq.size(); i++)
            if (nw.empty() || nw.back().second < seq[i].first.second) {
                nw.push_back(seq[i].first);
                res.push_back(seq[i].second);
            }
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] + 1 << (i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}
