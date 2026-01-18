#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

constexpr int Maxb = 50;

void Solve(int lvl, ll cur, ll mask, int lim, ll l, ll r, vector<llll>& res) {
    if (lvl == lim || l == 0 && r == (1ll << (lvl + 1)) - 1ll) {
        res.emplace_back(cur, cur + (1ll << (lvl + 1)) - 1ll);
        return;
    }
    ll ind = mask & 1ll << lvl;
    if (!(r & 1ll << lvl)) {
        Solve(lvl - 1, cur ^ ind, mask, lim, l, r, res);
        return;
    }
    if (l & 1ll << lvl) {
        Solve(lvl - 1, cur ^ ind ^ (1ll << lvl), mask, lim, l ^ (1ll << lvl), r ^ (1ll << lvl), res);
        return;
    }
    Solve(lvl - 1, cur ^ ind, mask, lim, l, (1ll << lvl) - 1ll, res);
    Solve(lvl - 1, cur ^ ind ^ (1ll << lvl), mask, lim, 0, r ^ (1ll << lvl), res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll l, r;
        cin >> l >> r;
        vector<llll> res;
        ll curl = 0, curr = 0;
        for (int i = Maxb - 1; i >= 0; i--) {
            if (l & 1ll << i) {
                Solve(Maxb - 1, 0, curl, i - 1, l, r, res);
                curl |= 1ll << i;
            }
            if (!(r & 1ll << i))
                Solve(Maxb - 1, 0, curr | 1ll << i, i - 1, l, r, res);
            else curr |= 1ll << i;
        }
        ranges::sort(res.begin(), res.end());
        ll nxt = 1, ans = 0;
        for (auto& [lef, rig] : res) {
            if (nxt < lef)
                ans += lef - nxt;
            nxt = max(nxt, rig + 1);
        }
        ans += (1ll << 50) - nxt;
        cout << ans << "\n";
    }
    return 0;
}
