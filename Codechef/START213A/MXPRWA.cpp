#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;
constexpr int mod = 998244353;

int toPower(int a, ll p) {
    int res = 1;
    while (p) {
        if (p & 1ll)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1ll;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

ll Solve(int v, int p, const vector<int>& a, const vector<vector<int>>& neigh,
    vector<ll>& subsum, vector<int>& negat, ll sum, int neg) {
    ll res = 0;
    subsum[v] += abs(a[v]);
    negat[v] += a[v] < 0;
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        res = max(res, Solve(u, v, a, neigh, subsum, negat, sum, neg));
        subsum[v] += subsum[u];
        negat[v] += negat[u];
        if (negat[u] % 2 == 0)
            res = max(res, subsum[u]);
    }
    if ((neg - negat[v]) % 2 == 0)
        res = max(res, sum - subsum[v]);
    return res;
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
        vector<int> a(n + 1);
        ll sum = 0;
        int neg = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += abs(a[i]);
            if (a[i] < 0)
                neg++;
        }
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        if (neg % 2 == 0) {
            cout << toPower(2, sum) << "\n";
            continue;
        }
        vector subsum(n + 1, 0ll);
        vector negat(n + 1, 0);
        auto res = Solve(1, 0, a, neigh, subsum, negat, sum, neg);
        cout << toPower(2, res) << "\n";
    }
    return 0;
}
