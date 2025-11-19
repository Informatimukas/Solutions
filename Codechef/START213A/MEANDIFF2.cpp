#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

constexpr int Inf = 1000000007;

void Add(vector<lli>& BIT, int x, const lli& value) {
    for (int i = x; i < BIT.size(); i += i & -i) {
        BIT[i].first += value.first;
        BIT[i].second += value.second;
    }
}

lli Get(const vector<lli>& BIT, int x) {
    lli res;
    for (int i = x; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res;
}

int getMin(int mx, const vector<int>& un, const vector<lli>& BIT) {
    int lef = 0, rig = mx - 1;
    while (lef <= rig) {
        int x = (lef + rig) / 2;
        auto [sum, k] = Get(BIT, distance(un.begin(),
            ranges::upper_bound(un, x)));
        if (sum + mx <= static_cast<ll>(k) * x + x + k)
            rig = x - 1;
        else lef = x + 1;
    }
    return lef;
}

int getMax(int mn, const vector<int>& un, const vector<lli>& BIT) {
    int lef = mn + 1, rig = Inf;
    while (lef <= rig) {
        int x = (lef + rig) / 2;
        auto [allsum, allk] = Get(BIT, un.size());
        auto [sum, k] = Get(BIT, distance(un.begin(),
            ranges::lower_bound(un, x)));
        sum = allsum - sum;
        k = allk - k;
        if (sum + mn >= x + static_cast<ll>(k) * x)
            lef = x + 1;
        else rig = x - 1;
    }
    return rig;
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
        vector un(a);
        ranges::sort(un);
        un.erase(ranges::unique(un).begin(), un.end());
        vector<lli> BIT(un.size() + 1);
        int mn = Inf, mx = -Inf;
        for (int i = 0; i < a.size(); i++) {
            auto ind = distance(un.begin(), ranges::lower_bound(un, a[i]));
            Add(BIT, ind + 1, {a[i], 1});
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            int res = max(getMax(mn, un, BIT) - mn, mx - getMin(mx, un, BIT));
            cout << res << (i + 1 < a.size() ? ' ' : '\n');
        }
    }
    return 0;
}
