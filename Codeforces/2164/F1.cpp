#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int mod = 998244353;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int C(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return static_cast<ll>(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

void Traverse(int v, int col, int splitter, vector<vector<int>>& neigh, vector<int>& a,
    array<vector<int>, 2>& seq, array<int, 2> lst) {
    if (col == 1)
        a[v] -= (splitter + 1);
    if (lst[col] == -1)
        seq[col].push_back(v);
    else
        neigh[lst[col]].push_back(v);
    lst[col] = v;
    vector<int> my = std::move(neigh[v]);
    neigh[v].clear();
    for (auto& u : my) {
        int ncol = a[u] <= splitter ? 0 : 1;
        Traverse(u, ncol, splitter + (ncol == 0), neigh, a, seq, lst);
    }
}

ii Solve(int v, vector<vector<int>>& neigh, vector<int>& a,
    const vector<int>& fac, const vector<int>& ifac) {
    if (a[v] != 0)
        return {0, 0};
    array<vector<int>, 2> seq{};
    for (auto& u : neigh[v]) {
        array lst = {-1, -1};
        int col = a[u] > 0;
        Traverse(u, col, col == 0, neigh, a, seq, lst);
    }
    neigh[v].clear();
    int res0 = 1;
    int res1 = 1;
    for (int i = 0; i < 2; i++) {
        int cnt = 0;
        for (auto& u : seq[i]) {
            ii got = Solve(u, neigh, a, fac, ifac);
            cnt += got.first;
            res1 = static_cast<ll>(res1) * got.second % mod *
                C(cnt, got.first, fac, ifac) % mod;
        }
        res0 += cnt;
    }
    return {res0, res1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector neigh(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
        }
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> fac(n + 1), ifac(n + 1);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
            ifac[i] = Inv(fac[i]);
        }
        auto res = Solve(1, neigh, a, fac, ifac);
        cout << res.second << "\n";
    }
    return 0;
}
