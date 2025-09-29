#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr int Maxd = 4;

struct node {
    int cov{0};
    array<int, Maxd> arr{};
    array<int, Maxd> Get() const {
        array<int, Maxd> res{};
        for (int i = 0; i < arr.size(); i++)
            res[min(Maxd - 1, i + cov)] += arr[i];
        return res;
    }
};

array<int, Maxd> Union(const node& a, const node& b) {
    auto gota = a.Get();
    auto gotb = b.Get();
    array<int, Maxd> res;
    for (int i = 0; i < res.size(); i++)
        res[i] = gota[i] + gotb[i];
    return res;
}

void Create(vector<node>& st, int v, int l, int r) {
    if (l == r)
        st[v].arr[0] = 1;
    else {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
        st[v].arr = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(vector<node>& st, int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b)
        st[v].cov += delt;
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].arr = Union(st[2 * v], st[2 * v + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p)
        cin >> x;
    vector add(n + 2, vector<ii>());
    vector rem(n + 2, vector<ii>());
    vector<node> st(4 * n);
    for (int i = 0; i < n; i++)
        if (i == n - 1 || p[i] < p[i + 1]) {
            int lim = i == n - 1 ? n : p[i + 1] - 1;
            add[1].emplace_back(p[i], lim);
            rem[p[i] + 1].emplace_back(p[i], lim);
        } else {
            add[p[i + 1] + 1].emplace_back(p[i], n);
            rem[p[i] + 1].emplace_back(p[i], n);
        }
    Create(st, 1, 1, n);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (auto& [fir, sec] : add[i])
            Update(st, 1, 1, n, fir, sec, 1);
        for (auto& [fir, sec] : rem[i])
            Update(st, 1, 1, n, fir, sec, -1);
        Update(st, 1, 1, n, i, i, Maxd - 1);
        res += n - st[1].Get()[Maxd - 1];
    }
    cout << res << "\n";
    return 0;
}