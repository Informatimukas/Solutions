#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Maxn = 200005;
constexpr int mod = 1000000007;

struct UnionSet {
    vector<ii> par;
    vector<int> siz;
    int comp;
    UnionSet(int n): par(n + 1), siz(n + 1, 1), comp(n) {
        for (int i = 1; i <= n; i++)
            par[i] = {i, 0};
    }
    ii getPar(int x) {
        if (x == par[x].first) return par[x];
        ii got = getPar(par[x].first);
        return par[x] = {got.first, par[x].second ^ got.second};
    }
    void Union(int x, int y, int val) {
        if (comp == 0) return;
        auto [a, aw] = getPar(x);
        auto [b, bw] = getPar(y);
        if (a == b) {
            if ((aw ^ bw) != val)
                comp = 0;
            return;
        }
        comp--;
        if (siz[a] < siz[b]) {
            swap(a, b);
            swap(aw, bw);
        }
        siz[a] += siz[b];
        par[b] = {a, aw ^ bw ^ val};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> ways(Maxn);
    ways[1] = 1;
    for (int i = 2; i < ways.size(); i++)
        ways[i] = static_cast<ll>(ways[i - 1]) * (1 << 30) % mod;
    int T;
    cin >> T;
    while (T--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        UnionSet unionSet(n + m);
        while (k--) {
            int r, c, val;
            cin >> r >> c >> val;
            unionSet.Union(r, n + c, val);
        }
        cout << ways[unionSet.comp] << "\n";
        while (q--) {
            int r, c, val;
            cin >> r >> c >> val;
            unionSet.Union(r, n + c, val);
            cout << ways[unionSet.comp] << "\n";
        }
    }
    return 0;
}
