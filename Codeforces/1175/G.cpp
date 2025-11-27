// Next steps: the solution relies on the idea of doing undo operations for the convex hull;
// It currently has inefficiency of relying on interval queries for one given max;
// It gets MLE probably because of that. Trying to get rid of that would probably improve
// performance.
#include <bits/stdc++.h>
using namespace std;

using ll = int;

constexpr ll Inf = 1000000000ll;

const ll is_query = -(1LL<<30);
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
    void insert_line(ll m, ll b, vector<Line>* mem, optional<Line>* sav) {
        auto y = insert({ -m, -b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        if (sav)
            *sav = {*y};
        while (next(y) != end() && bad(next(y))) {
            if (mem)
                mem->push_back(*next(y));
            erase(next(y));
        }
        while (y != begin() && bad(prev(y))) {
            if (mem)
                mem->emplace_back(*prev(y));
            erase(prev(y));
        }
    }
    ll eval(ll x) {
        if (empty())
            return Inf;
        auto l = *lower_bound((Line) { x, is_query });
        return -l.m * x - l.b;
    }
};

void addBIT(vector<HullDynamic>& BIT, ll ind, ll val) {
    for (int i = ind + 1; i > 0; i -= i & -i)
        BIT[i].insert_line(-ind, val, nullptr, nullptr);
}

ll getBIT(vector<HullDynamic>& BIT, int key, ll ind, ll a) {
    ll res = Inf;
    for (int i = key + 1; i < BIT.size(); i += i & -i)
        res = min(res, BIT[i].eval(a));
    if (res >= Inf)
        return res;
    res += (ind + 1) * a;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector BIT(k, vector<HullDynamic>(n + 1));
    vector<HullDynamic> hd(k);
    addBIT(BIT[0], 0, 0);
    vector mem(n, vector(k, vector<Line>()));
    vector my(n, vector<optional<Line>>(k));
    vector<int> S;
    for (int i = 0; i < n; i++) {
        while (!S.empty() && a[S.back()] <= a[i]) {
            int ind = S.back();
            for (int j = 0; j < k; j++) {
                for (auto& l : mem[ind][j])
                    hd[j].insert(l);
                mem[ind][j].clear();
                mem[ind][j].shrink_to_fit();
                if (my[ind][j])
                    hd[j].erase(*my[ind][j]);
            }
            S.pop_back();
        }
        int from = S.empty() ? 0 : S.back() + 1;
        S.push_back(i);
        for (int j = 0; j < k; j++) {
            ll val = getBIT(BIT[j], from, i, a[i]);
            hd[j].insert_line(a[i], -i * a[i] + val, &mem[i][j], &my[i][j]);
            if (i + 1 < n && j + 1 < k) {
                ll got = hd[j].eval(i);
                addBIT(BIT[j + 1], i + 1, got);
            }
        }
    }
    ll res = hd[k - 1].eval(n - 1);
    cout << res << "\n";
    return 0;
}
