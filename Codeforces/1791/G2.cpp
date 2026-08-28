#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll sum{0};
    ll cnt{0};
};

ll Get(const vector<node>& st, int v, int l, int r, ll k) {
    if (st[v].cnt == 0)
        return 0;
    if (l == r) {
        ll one = st[v].sum / st[v].cnt;
        return min(st[v].cnt, k / one);
    }
    int m = (l + r) / 2;
    if (k <= st[2 * v].sum)
        return Get(st, 2 * v, l, m, k);
    return Get(st, 2 * v + 1, m + 1, r, k - st[2 * v].sum) + st[2 * v].cnt;
}

void Update(vector<node>& st, int v, int l, int r, int x, ll add) {
    st[v].cnt++;
    st[v].sum += add;
    if (l == r)
        return;
    int m = (l + r) / 2;
    if (x <= m)
        Update(st, 2 * v, l, m, x, add);
    else Update(st, 2 * v + 1, m + 1, r, x, add);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n + 1);
        vector<int> un;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int best = min(a[i] + i, n + 1 - i + a[i]);
            un.push_back(best);
        }
        ranges::sort(un);
        un.erase(ranges::unique(un).begin(), un.end());
        vector<node> st(4 * un.size() + 5);
        ll res = 0;
        for (int i = n; i >= 1; i--) {
            ll cand = a[i] + i;
            if (cand <= c)
                res = max(res, 1 + Get(st, 1, 0, un.size() - 1, c - cand));
            int ind = distance(un.begin(), ranges::lower_bound(un, min(a[i] + i, n + 1 - i + a[i])));
            Update(st, 1, 0, un.size() - 1, ind, un[ind]);
        }
        cout << res << "\n";
    }
    return 0;
}
