#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<array<ii, 2>> Get(set<ii>& S, int key) {
    vector<array<ii, 2>> res;
    auto it = S.lower_bound({key + 1, 0});
    --it;
    ii cur = *it;
    S.erase(it++);
    optional<ii> lef, rig;
    ii my = {key, key};
    if (cur.first < key) {
        lef = {{cur.first, key - 1}};
        S.insert(lef.value());
    } else if (it != S.begin()) {
        --it;
        my.first = it->first;
        S.erase(it++);
        if (it != S.begin()) {
            --it;
            lef = *it;
            ++it;
        }
    }
    if (key < cur.second) {
        rig = {{key + 1, cur.second}};
        S.insert(rig.value());
    } else if (it != S.end()) {
        my.second = it->second;
        S.erase(it++);
        if (it != S.end())
            rig = *it;
    }
    S.insert(my);
    if (lef)
        res.push_back({lef.value(), my});
    if (rig)
        res.push_back({my, rig.value()});
    return res;
}

void Update(vector<vector<ii>>& st, int v, int l, int r, int a, int b, int c, int d) {
    if (l == a && r == b) {
        if (st[v].empty() || st[v].back().second + 1 < c)
            st[v].emplace_back(c, d);
        else st[v].back().second = max(st[v].back().second, d);
    } else {
        int m = l + r >> 1;
        if (a <= m) Update(st, 2 * v, l, m, a, min(m, b), c, d);
        if (m + 1 <= b) Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, c, d);
    }
}

bool Check(const vector<vector<ii>>& st, int v, int l, int r, int a, int b) {
    auto ind = distance(st[v].begin(), ranges::lower_bound(st[v], ii{b + 1, 0})) - 1;
    if (ind >= 0 && b <= st[v][ind].second)
        return true;
    if (l == r) return false;
    int m = l + r >> 1;
    if (a <= m)
        return Check(st, 2 * v, l, m, a, b);
    return Check(st, 2 * v + 1, m + 1, r, a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), ina(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        ina[a[i]] = i;
    }
    set<ii> S = {{0, n - 1}};
    vector<array<ii, 2>> all;
    for (int i = 0; i < n; i++) {
        auto got = Get(S, ina[i]);
        all.insert(all.end(), got.begin(), got.end());
    }
    ranges::sort(all, [](const auto& a, const auto& b) {
        return a[1] < b[1];
    });
    vector<vector<ii>> st(4 * n);
    for (auto& x : all)
        Update(st, 1, 0, n - 1, x[0].first, x[0].second, x[1].first, x[1].second);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << (Check(st, 1, 0, n - 1, l, r)? "YES": "NO") << "\n";
        if (i % 10 == 0)
            cout.flush();
    }
    return 0;
}
