#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

struct BIT {
    vector<int> val;
    vector<int> un;
    int tot;
    BIT() = default;
    void Change(int x, int delt) {
        auto ind = distance(un.begin(), ranges::lower_bound(un, x)) + 1;
        for (int i = ind; i < val.size(); i += i & -i)
            val[i] += delt;
        tot += delt;
    }
    int getSmaller(int x) {
        if (tot == 0)
            return 0;
        int res = 0;
        int ind = distance(un.begin(), ranges::lower_bound(un, x));
        for (int i = ind; i > 0; i -= i & -i)
            res += val[i];
        return res;
    }
    int getBigger(int x) {
        if (tot == 0)
            return 0;
        return tot - getSmaller(x + 1);
    }
    BIT(vector<int>&& gun): val(gun.size() + 1, 0), un(std::move(gun)), tot(0) {}
};

vector<vector<int>> getPoints(vector<int> P, vector<int> Q,
    const vector<array<int, 3>>& quer) {
    vector res(P.size(), vector<int>());
    for (int i = 1; i < P.size(); i++)
        res[P[i]].push_back(Q[i]);
    for (auto& [typ, a, b] : quer) {
        if (typ == 1)
            swap(P[a], P[b]);
        else swap(Q[a], Q[b]);
        res[P[a]].push_back(Q[a]);
        res[P[b]].push_back(Q[b]);
    }
    return res;
}

void Create(vector<BIT>& st, int v, int l, int r, const vector<vector<int>>& points) {
    vector<int> un;
    if (l == r) {
        un = points[l];
        ranges::sort(un);
        un.erase(ranges::unique(un).begin(), un.end());
    } else {
        int m = l + r >> 1;
        int lc = 2 * v, rc = 2 * v + 1;
        Create(st, lc, l, m, points);
        Create(st, rc, m + 1, r, points);
        ranges::set_union(st[lc].un, st[rc].un, back_inserter(un));
    }
    cout << "created " << l << " " << r << endl;
    for (auto& x : un)
        cout << " " << x;
    cout << endl;
    st[v] = BIT(std::move(un));
    for (auto& x : st[v].un)
        cout << " " << x;
    cout << endl;
    for (auto& x : st[v].val)
        cout << " " << x;
    cout << endl;
}

void Change(vector<BIT>& st, int v, int l, int r, int x, int y, int delt) {
    st[v].Change(y, delt);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m)
            Change(st, 2 * v, l, m, x, y, delt);
        else Change(st, 2 * v + 1, m + 1, r, x, y, delt);
    }
}

int getSmaller(vector<BIT>& st, int v, int l, int r, int x, int y) {
    if (r < x)
        return st[v].getSmaller(y);
    if (x <= l)
        return 0;
    int m = l + r >> 1;
    int res = getSmaller(st, 2 * v, l, m, x, y) +
        getSmaller(st, 2 * v + 1, m + 1, r, x, y);
    return res;
}

int getBigger(vector<BIT>& st, int v, int l, int r, int x, int y) {
    if (x < l)
        return st[v].getBigger(y);
    if (r <= x)
        return 0;
    int m = l + r >> 1;
    int res = getBigger(st, 2 * v, l, m, x, y) +
        getBigger(st, 2 * v + 1, m + 1, r, x, y);
    return res;
}

int Action(vector<BIT>& st, int n, int fir, int sec, int delt) {
    Change(st, 1, 1, n, fir, sec, delt);
    int res = getSmaller(st, 1, 1, n, fir, sec) +
        getBigger(st, 1, 1, n, fir, sec);
    cout << "Action " << fir << " " << sec << " " << res << " " << delt << endl;
    return res * delt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> P(n + 1), Q(n + 1);
        vector<int> inP(n + 1), inQ(n + 1);
        vector<array<int, 3>> quer(q);
        for (int i = 1; i <= n; i++)
            cin >> P[i];
        for (int i = 1; i <= n; i++)
            cin >> Q[i];
        for (auto& x : quer)
            cin >> x[0] >> x[1] >> x[2];
        auto points = getPoints(P, Q, quer);
        for (int i = 0; i < points.size(); i++) {
            cout << "points " << i << endl;
            for (auto& x : points[i])
                cout << " " << x;
            cout << endl;
        }
        vector<BIT> st(4 * n);
        Create(st, 1, 1, n, points);
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += Action(st, n, P[i], Q[i], 1);
        cout << "res = " << res << endl;
        for (auto& [typ, a, b] : quer) {
            res += Action(st, n, P[a], Q[a], -1);
            res += Action(st, n, P[b], Q[b], -1);
            cout << "res = " << res << endl;
            if (typ == 1)
                swap(P[a], P[b]);
            else swap(Q[a], Q[b]);
            res += Action(st, n, P[a], Q[a], 1);
            res += Action(st, n, P[b], Q[b], 1);
            cout << "res = " << res << endl;
            cout << static_cast<ll>(n) * n - res << "\n";
        }
    }
    return 0;
}