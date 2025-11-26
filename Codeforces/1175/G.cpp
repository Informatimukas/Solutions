#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 20005;
constexpr ll Inf = 1000000000000000000ll;

const ll is_query = -(1LL<<62);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ -m, -b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return -l.m * x - l.b;
    }
};

void addSmallBIT(vector<HullDynamic>& BIT, int ind, ll a, ll b) {
    for (int i = ind; i < BIT.size(); i += i & -i)
        BIT[i].insert_line(a, b);
}

ll getSmallBIT(vector<HullDynamic>& BIT, int ind, ll x) {
    ll res = Inf;
    for (int i = ind; i > 0; i -= i & -i)
        if (!BIT[i].empty())
            res = min(res, BIT[i].eval(x));
    return res;
}

void addBigBIT(vector<HullDynamic>& BIT, int ind, ll a, ll b) {
    for (int i = ind; i > 0; i -= i & -i)
        BIT[i].insert_line(a, b);
}

ll getBigBIT(vector<HullDynamic>& BIT, int ind, ll x) {
    ll res = Inf;
    for (int i = ind; i < BIT.size(); i += i & -i)
        if (!BIT[i].empty())
            res = min(res, BIT[i].eval(x));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    HullDynamic hd;
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), L(n + 1), R(n + 1);
    vector<int> S;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (!S.empty() && a[S.back()] <= a[i])
            S.pop_back();
        L[i] = S.empty() ? 0 : S.back();
        S.push_back(i);
    }
    S.clear();
    for (int i = n; i >= 1; i--) {
        while (!S.empty() && a[S.back()] < a[i])
            S.pop_back();
        R[i] = S.empty() ? n + 1 : S.back();
        S.push_back(i);
    }
    vector st(k, )
    for (auto& x : a)
        cin >> x;
    vector<int> L(n);

    vector<int> rig(n);
    for (int i = n - 1; i >= 0; i--) {
        rig[i] = a[i];
        if (i + 1 < n)
            rig[i] = max(rig[i], rig[i + 1]);
    }
    ll res = Inf;
    vector smallBIT(k, vector<HullDynamic>(Maxn));
    vector bigBIT(k, vector<HullDynamic>(Maxn));
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        for (int j = k - 1; j >= 0; j--) {
            if (j == 0 && mx != a[i])
                continue;
            ll val = j == 0 ? a[i] * (i + 1) :
                min(getSmallBIT(smallBIT[j], a[i], i) + a[i],
                    getBigBIT(bigBIT[j], a[i] + 1, a[i]) + a[i] * i);
            cout << "i = " << i << ", j = " << j << ", val = " << val << endl;
            if (val >= Inf)
                continue;
            if (j + 1 == k) {
                if (rig[i] == a[i])
                    res = min(res, val + a[i] * (n - 1 - i));
                continue;
            }
            addSmallBIT(smallBIT[j + 1], a[i], a[i], a[i] * (-i - 1) + val);
            addBigBIT(bigBIT[j + 1], a[i], -i, val);
        }
    }
    cout << res << "\n";
    return 0;
}
