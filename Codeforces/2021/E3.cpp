#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct UnionSet {
    vector<int> par, siz, spec;
    vector<multiset<ll>> my;
    vector<ll> fir;
    UnionSet(int n): par(n + 1), siz(n + 1, 1), spec(n + 1, 0), my(n + 1), fir(n + 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    void Union(int a, int b, ll w) {
        a = getPar(a);
        b = getPar(b);
        if (a == b)
            return;
        if (siz[a] < siz[b])
            swap(a, b);
        if (spec[a] == 0) {
            fir[a] = fir[b];
            my[a] = my[b];
        } else if (spec[b] > 0) {
            ll cura = spec[a] * w;
            my[a].insert(cura - fir[a]);
            ll curb = spec[b] * w;
            my[b].insert(curb - fir[b]);
            my[a].insert(my[b].begin(), my[b].end());
            fir[a] = cura + curb - *my[a].rbegin();
            my[a].erase(prev(my[a].end()));
        }
        spec[a] += spec[b];
        siz[a] += siz[b];
        par[b] = a;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, p;
        cin >> n >> m >> p;
        UnionSet U(n);
        for (int i = 1; i <= p; i++) {
            int s;
            cin >> s;
            U.spec[s] = 1;
            U.fir[s] = 0;
        }
        vector<array<int, 3>> E(m);
        for (auto& arr : E)
            cin >> arr[1] >> arr[2] >> arr[0];
        ranges::sort(E);
        for (auto& [w, a, b] : E)
            U.Union(a, b, w);
        int root = U.getPar(1);
        auto& S = U.my[root];
        ll cur = U.fir[root];
        for (int i = 1; i <= n; i++) {
            cout << cur << (i + 1 <= n ? ' ' : '\n');
            if (!S.empty()) {
                cur -= *S.rbegin();
                S.erase(prev(S.end()));
            }
        }
    }
    return 0;
}
