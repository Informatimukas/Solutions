#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

void Add(vector<llll>& BIT, int ind, const llll& p) {
    for (int i = ind; i < BIT.size(); i += i & -i) {
        BIT[i].first += p.first;
        BIT[i].second += p.second;
    }
}

llll Get(const vector<llll>& BIT, int ind) {
    llll res;
    for (int i = ind; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> add(m + 2);
    vector<vector<array<int, 2>>> rem(m + 2);
    vector<vector<array<int, 4>>> quer(m + 2);
    vector<ll> res(q);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        add[l].push_back({i});
        rem[r + 1].push_back({i, l});
    }
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        quer[c - 1].push_back({a, b, -1, i});
        quer[d].push_back({a, b, 1, i});
    }
    vector<llll> BIT(n + 1);
    for (int i = 1; i <= m; i++) {
        for (auto x : add[i])
            Add(BIT, x, {-(i - 1), 1});
        for (auto& [x, l] : rem[i])
            Add(BIT, x, {(l - 1) + i - l, -1});
        for (auto& [a, b, delt, ind] : quer[i]) {
            auto cur = Get(BIT, b);
            auto sub = Get(BIT, a - 1);
            cur.first -= sub.first;
            cur.second -= sub.second;
            ll ans = cur.first + cur.second * i;
            res[ind] += ans * delt;
        }
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
    return 0;
}
