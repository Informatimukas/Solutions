#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

iii Solve(int lvl, int x, int y) {
    if (lvl < 0)
        return {0, {0, 0}};
    bool sw = x > y;
    if (sw)
        swap(x, y);
    iii best;
    if (x & 1 << lvl) {
        int cur = (1ll << lvl + 1ll) - 1ll;
        best = {x + y - cur, {(1 << lvl) - 1, 1 << lvl}};
    } else if (y & 1 << lvl) {
        best = Solve(lvl - 1, x, y ^ (1 << lvl));
        best.second.second |= 1 << lvl;
    } else {
        best = Solve(lvl - 1, x, y);
        if (lvl <= 30)
            best = min(best, {(1 << lvl) - y, {x, 1 << lvl}});
    }
    if (sw)
        swap(best.second.first, best.second.second);
    return best;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        auto res = Solve(31, x, y).second;
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}
