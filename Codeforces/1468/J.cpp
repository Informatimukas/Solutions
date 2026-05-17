#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;

struct UnionSet {
    vector<int> par, siz;
    int comp;
    UnionSet(int n): par(n + 1), siz(n + 1, 1), comp(n) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    bool unionSet(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return false;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        comp--;
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        UnionSet US(n);
        vector<array<int, 3>> E(m);
        for (auto& a : E)
            for (auto& x : a)
                cin >> x;
        ranges::sort(E, {}, [](auto&& x) { return x[2]; });
        ll res = Inf;
        int pnt = 0;
        while (pnt < E.size() && E[pnt][2] <= k) {
            res = k - E[pnt][2];
            US.unionSet(E[pnt][0], E[pnt][1]);
            pnt++;
        }
        if (US.comp != 1)
            res = Inf;
        ll cand = 0;
        optional<ll> first;
        while (pnt < E.size()) {
            if (!first.has_value())
                first = E[pnt][2] - k;
            if (US.unionSet(E[pnt][0], E[pnt][1]))
                cand += E[pnt][2] - k;
            pnt++;
        }
        if (first.has_value())
            res = min(res, max(*first, cand));
        cout << res << "\n";
    }
    return 0;
}
