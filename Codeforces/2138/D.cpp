#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int mod = 1000000007;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int Ways(int target, int val, int S, int F, const vector<int>& inv) {
    if (S == 0 && F == 0) return val >= target;
    return static_cast<ll>(S) * inv[S + F] % mod;
}

int Solve(const vector<int>& inv, const vector<ii>& seq, vector<int> un, int ind, int val) {
    int res = 0;
    vector<int> X, Y, Z;
    for (auto& [val, u] : seq) {
        int rval = val + ind;
        if (u < ind) X.push_back(rval);
        else if (u > ind) Y.push_back(rval);
        else Z.push_back(rval);
    }
    auto it = ranges::lower_bound(un, val - ind);
    if (it == un.end() || val - ind < *it)
        un.insert(it, val - ind);
    int S = X.size() + Z.size(), F = 0;
    int pntX = 0, pntY = 0, pntZ = 0;
    for (int i = 0; i < un.size(); i++) {
        int rval = un[i] + ind;
        while (pntX < X.size() && X[pntX] < rval) {
            S--;
            pntX++;
        }
        while (pntY < Y.size() && Y[pntY] < rval) {
            F++;
            pntY++;
        }
        while (pntZ < Z.size() && Z[pntZ] < rval) {
            F++;
            S--;
            pntZ++;
        }
        int mult = i ? un[i] - un[i - 1] : rval;
        res = (res + static_cast<ll>(mult) * Ways(rval, val, S, F, inv)) % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> inv(q + 1);
        for (int i = 1; i <= q; i++)
            inv[i] = Inv(i);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<ii> seq;
        for (int i = 1; i <= q; i++) {
            int ind, x;
            cin >> ind >> x;
            seq.emplace_back(x - ind, ind);
        }
        ranges::sort(seq);
        vector<int> un;
        for (auto & i : seq)
            un.push_back(i.first);
        un.erase(ranges::unique(un).begin(), un.end());
        int fac = 1;
        for (int i = 1; i <= q; i++)
            fac = static_cast<ll>(fac) * i % mod;
        for (int i = 1; i <= n; i++) {
            int res = static_cast<ll>(fac) * Solve(inv, seq, un, i, a[i]) % mod;
            cout << res << (i + 1 <= n? ' ': '\n');
        }
    }
    return 0;
}
