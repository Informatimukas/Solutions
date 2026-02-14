#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, n;
    cin >> h >> w >> n;
    vector taken(n, false);
    vector<ii> byh(n), byw(n);
    vector<ii> my(n);
    vector<ii> res(n);
    for (int i = 0; i < n; i++) {
        int myh, myw;
        cin >> myh >> myw;
        my[i] = {myh, myw};
        byh.emplace_back(myh, i);
        byw.emplace_back(myw, i);
    }
    ranges::sort(byh, greater());
    ranges::sort(byw, greater());
    int i = 0, j = 0;
    while (i < byh.size() || j < byw.size())
        if (i < byh.size() && (j >= byw.size() || byh[i].first >= h)) {
            if (!taken[byh[i].second]) {
                w -= my[byh[i].second].second;
                res[byh[i].second] = {1, w + 1};
                taken[byh[i].second] = true;
            }
            ++i;
        } else {
            if (!taken[byw[j].second]) {
                h -= my[byw[j].second].first;
                res[byw[j].second] = {h + 1, 1};
                taken[byw[j].second] = true;
            }
            ++j;
        }
    for (auto& p : res)
        cout << p.first << " " << p.second << '\n';
    return 0;
}
