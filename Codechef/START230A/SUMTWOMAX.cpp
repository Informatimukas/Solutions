#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Inf = 1000000000;

ii Join(const ii& a, const ii& b) {
    ii res;
    res.first = min(a.first, b.first);
    int acand = a.first == res.first ? a.second : a.first;
    int bcand = b.first == res.first ? b.second : b.first;
    res.second = min(acand, bcand);
    return res;
}

void Update(vector<ii>& BIT, int x, int val) {
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] = {val, BIT[i].first};
}

ii Get(const vector<ii>& BIT, int x) {
    ii res = {Inf, Inf};
    for (int i = x; i < BIT.size(); i += i & -i)
        res = Join(res, BIT[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<ii> BIT(n + 1, {n, n});
        vector<ii> rig(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            rig[i] = Get(BIT, a[i]);
            Update(BIT, a[i], i);
        }
        BIT = vector<ii>(n + 1, {1, 1});
        vector<ii> lef(n + 1);
        ll res = 0;
        for (int i = 0; i < n; i++) {
            lef[i] = Get(BIT, a[i]);
            Update(BIT, a[i], -i);
            swap(lef[i].first, lef[i].second);
            lef[i].first = -lef[i].first;
            lef[i].second = -lef[i].second;
            ll tot = static_cast<ll>(i - lef[i].second) * (rig[i].second - i);
            tot += static_cast<ll>(rig[i].first - i) * (i - lef[i].first);
            tot -= 2 * static_cast<ll>(i - lef[i].second) * (rig[i].first - i);
            res += tot * a[i];
        }
        cout << res << "\n";
    }
    return 0;
}
