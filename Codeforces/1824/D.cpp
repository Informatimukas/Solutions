#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;
using llll = pair<ll, ll>;

struct pos {
    llll val{0, 0};
    ll el{0}, delt{0};
};

llll operator+(const llll& a, const llll& b) {
    return {a.first + b.first, a.second + b.second};
}

void downOn(vector<pos>& st, int v, int siz, ll fel, ll fdelt) {
    st[v].val.first = fel * siz;
    st[v].val.second += fdelt * siz;
    st[v].el = fel;
    st[v].delt += fdelt;
}

void Down(vector<pos>& st, int v, int l, int m, int r) {
    if (st[v].el || st[v].delt) {
        downOn(st, 2 * v, m + 1 - l, st[v].el, st[v].delt);
        downOn(st, 2 * v + 1, r - m, st[v].el, st[v].delt);
        st[v].el = st[v].delt = 0;
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, ll fel, ll fdelt) {
    if (l == a && r == b)
        downOn(st, v, r - l + 1, fel, fdelt);
    else {
        int m = (l + r) / 2;
        Down(st, v, l, m, r);
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), fel, fdelt);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, fel, fdelt);
        st[v].val = st[2 * v].val + st[2 * v + 1].val;
    }
}

llll Get(vector<pos>& st, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return st[v].val;
    int m = (l + r) / 2;
    Down(st, v, l, m, r);
    llll res = {0, 0};
    if (a <= m)
        res = res + Get(st, 2 * v, l, m, a, min(m, b));
    if (m + 1 <= b)
        res = res + Get(st, 2 * v + 1, m + 1, r, max(m + 1, a), b);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<ii> xy(q);
    vector res(q, 0ll);
    vector quer(n + 1, vector<ii>());
    for (int i = 0; i < q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        xy[i] = {x, y};
        quer[l].emplace_back(i, 1);
        if (r < n)
            quer[r + 1].emplace_back(i, -1);
    }
    vector lst(n + 1, n + 1);
    vector<pos> st(4 * n);
    vector<ii> seq;
    for (int i = n; i >= 1; i--) {
        int rig = lst[a[i]] - 1;
        lst[a[i]] = i;
        Update(st, 1, 1, n, i, i, i, static_cast<ll>(i) * (i + 1));
        ll cur = i;
        while (cur != rig) {
            int from = cur + 1;
            int to = min(rig, seq.back().second);
            Update(st, 1, 1, n, from, to, i,
                static_cast<ll>(i - seq.back().first) * (i + 1));
            cur = to;
            if (seq.back().second <= cur)
                seq.pop_back();
        }
        seq.emplace_back(i, rig);
        for (auto& [ind, mult] : quer[i]) {
            auto got = Get(st, 1, 1, n, xy[ind].first, xy[ind].second);
            ll val = -got.first * i + got.second;
            res[ind] += mult * val;
        }
    }
    for (auto r : res)
        cout << r << "\n";
    return 0;
}
