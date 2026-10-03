#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr ll mod = 1000000007;
const vector dx = {-1, 0, 1, 0};
const vector dy = {0, -1, 0, 1};

struct UnionSet {
    int n;
    vector<int> siz, par, edges, loop;
    UnionSet(int n): siz(n, 1), par(n), edges(n), loop(n) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    void unionSet(int a, int b) {
        if (a == b) {
            a = getPar(a);
            edges[a]++;
            loop[a] = 1;
            return;
        }
        a = getPar(a), b = getPar(b);
        edges[a]++;
        if (a == b)
            return;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        edges[a] += edges[b];
        loop[a] |= loop[b];
    }
};

int getId(int r, int c, int m) {
    return (r - 1) * m + c - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        UnionSet US(n * m);
        vector<ii> seq(k + 1);
        for (auto& [a, b] : seq)
            cin >> a >> b;
        ll res = 1;
        for (int i = 0; i < k; i++) {
            vector<ii> good;
            for (int d = 0; d < dx.size(); d++) {
                int na = seq[i].first + dx[d], nb = seq[i].second + dy[d];
                if (1 <= na && na <= n && 1 <= nb && nb <= m &&
                    abs(na - seq[i + 1].first) + abs(nb - seq[i + 1].second) == 1)
                    good.emplace_back(na, nb);
            }
            if (good.empty()) {
                res = 0;
                break;
            }
            if (good.size() == 1)
                good.push_back(good[0]);
            US.unionSet(getId(good[0].first, good[0].second, m), getId(good[1].first, good[1].second, m));
        }
        for (int i = 0; i < n * m; i++)
            if (US.getPar(i) == i)
                if (US.edges[i] == US.siz[i] - 1)
                    res = res * US.siz[i] % mod;
                else if (US.edges[i] > US.siz[i])
                    res = 0;
                else if (!US.loop[i])
                    res = res * 2 % mod;
        cout << res << "\n";
    }
    return 0;
}
