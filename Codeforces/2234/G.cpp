#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

void Add(int ind, map<int, int>& winners, set<iii>& srt) {
    int lef = ind, rig = ind;
    auto it = winners.upper_bound(ind);
    if (it != winners.end() && ind + 1 == it->first) {
        srt.erase({it->second - it->first, *it});
        rig = it->second;
        winners.erase(it++);
    }
    if (it != winners.begin()) {
        --it;
        if (it->second + 1 == ind) {
            srt.erase({it->second - it->first, *it});
            lef = it->first;
            winners.erase(it++);
        } else ++it;
    }
    winners.insert(it, {lef, rig});
    srt.insert({rig - lef, {lef, rig}});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        set<iii> srt;
        map<int, int> winners;
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<int>> add(n + 1);
        for (int i = 1; i <= n; i++)
            add[n + 1 - i].push_back(i);
        for (int i = n; i > 1; i--) {
            while (!srt.empty()) {
                auto it = prev(srt.end());
                if (it->first < a[i])
                    break;
                auto [lef, rig] = it->second;
                srt.erase(it);
                winners.erase(lef);
                while (rig - lef >= a[i]) {
                    if (i - lef >= 1)
                        add[i - lef].push_back(lef);
                    lef++;
                }
                if (lef <= rig) {
                    srt.insert({rig - lef, {lef, rig}});
                    winners.insert({lef, rig});
                }
            }
            for (auto ind : add[i])
                Add(ind, winners, srt);
        }
        auto it = winners.begin();
        if (it != winners.end() && it->first == 1 && it->second - it->first >= a[1])
            cout << "2\n";
        else cout << "1\n";
    }
    return 0;
}
