#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

struct pos {
    ll sum{0};
    int cnt{0};
};

pos Merge(const pos& a, const pos& b) {
    return {a.sum + b.sum, a.cnt + b.cnt};
}

void Add(vector<pos>& st, int v, int l, int r, int x, const vector<int>& un) {
    if (l == r) {
        st[v].sum += un[x];
        st[v].cnt++;
    } else {
        int m = (l + r) / 2;
        if (x <= m)
            Add(st, 2 * v, l, m, x, un);
        else Add(st, 2 * v + 1, m + 1, r, x, un);
        st[v] = Merge(st[2 * v], st[2 * v + 1]);
    }
}

ll Solve(const vector<pos>& st, int v, int l, int r, ll y, const vector<int>& un) {
    if (st[v].sum <= y)
        return st[v].cnt;
    if (l == r)
        return y / un[l];
    int m = (l + r) / 2;
    if (st[2 * v].sum <= y)
        return st[2 * v].cnt + Solve(st, 2 * v + 1, m + 1, r, y - st[2 * v].sum, un);
    return Solve(st, 2 * v, l, m, y, un);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> un;
    vector<vector<ii>> queries(n + 1);
    vector<ll> res(q);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        un.push_back(a[i]);
    }
    ranges::sort(un);
    un.erase(ranges::unique(un).begin(), un.end());
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        queries[x].emplace_back(y, i);
    }
    vector<pos> st(4 * n);
    for (int i = 1; i <= n; i++) {
        auto ind = distance(un.begin(), ranges::lower_bound(un, a[i]));
        Add(st, 1, 0, un.size() - 1, ind, un);
        for (auto& [y, qind] : queries[i])
            res[qind] = Solve(st, 1, 0, un.size() - 1, y, un);
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
    return 0;
}
