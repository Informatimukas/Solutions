#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

struct UnionSet {
    vector<int> par, siz;
    UnionSet(int n): par(n), siz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    void unionSet(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
    }
};

ll Get(ll siz) { return siz * (siz + 1) / 2; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<vector<int>> seq(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (i)
                seq[abs(p[i] - p[i - 1])].push_back(i - 1);
        }
        UnionSet US(n);
        ll cur = n;
        vector<ll> res(n);
        for (int i = n - 1; i > 0; i--) {
            for (auto u : seq[i]) {
                cur -= Get(US.siz[US.getPar(u)]);
                cur -= Get(US.siz[US.getPar(u + 1)]);
                US.unionSet(u, u + 1);
                cur += Get(US.siz[US.getPar(u)]);
            }
            res[i] = cur - n;
        }
        for (int i = 1; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
