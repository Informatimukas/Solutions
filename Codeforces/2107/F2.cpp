#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const ll Inf = 1000000000000000000ll;

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
        m = -m; b = -b;
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return -(l.m * x + l.b);
    }
};

int T;
int n;
int a[Maxn];
ll dp[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            dp[i] = static_cast<ll>(i) * (1 + a[i]);
        map<int, HullDynamic> M;
        HullDynamic all;
        for (int i = 0; i < n; i++) {
            if (!all.empty())
                dp[i] = min(dp[i], all.eval(i - 1) + i - 1);
            auto it = M.find(a[i]);
            if (it != M.end()) {
                auto &hd = it->second;
                dp[i] = min(dp[i], hd.eval(i - 1));
            }
            M[a[i]].insert_line(a[i] + 1, dp[i] + a[i] - static_cast<ll>(i) * (a[i] + 1));
            all.insert_line(a[i] + 1, dp[i] - i + a[i] - static_cast<ll>(i) * (a[i] + 1));
            ll res = all.eval(i) + i;
            printf("%lld%c", res, i + 1 < n? ' ': '\n');
        }
    }
    return 0;
}
