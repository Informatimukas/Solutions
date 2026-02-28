#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

constexpr ll mod = 998244353;
constexpr ll inv2 = (mod + 1) / 2;

struct UnionSet {
    vector<int> par, siz;
    int comp;
    UnionSet(int n): par(n + 1), siz(n + 1, 1), comp(n) {
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
        --comp;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ii> E(m);
    ll sum = 0;
    ll cur = 1;
    for (int i = 0; i < m; i++) {
        cur = 2 * cur % mod;
        sum = (sum + cur) % mod;
        cin >> E[i].first >> E[i].second;
    }
    UnionSet US(n);
    for (int i = m - 1; i >= 0; i--) {
        auto [a, b] = E[i];
        if (US.getPar(a) != US.getPar(b) && US.comp > 2) {
            US.unionSet(a, b);
            sum = (sum - cur + mod) % mod;
        } else if (US.getPar(a) == US.getPar(b))
            sum = (sum - cur + mod) % mod;
        cur = cur * inv2 % mod;
    }
    cout << sum << "\n";
    return 0;
}
