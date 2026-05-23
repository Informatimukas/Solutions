#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct UnionSet {
    vector<int> par, siz;
    vector<bool> bad;
    vector<ll> sum;
    UnionSet(int n): par(n), siz(n, 1), bad(n, false), sum(n) {
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
        bad[a] = bad[a] || bad[b];
        sum[a] += sum[b];
    }
};

int getId(int r, int c, int m) {
    return r * (m - 1) + c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        UnionSet US((n - 1) * (m - 1));
        vector w(n, vector<ll>(m));
        vector v(n, vector<ll>(m));
        vector<string> p(n), q(n);
        for (int i = 0; i < n - 1; i++)
            for (auto& x : w[i])
                cin >> x;
        for (auto& x : v)
            for (int i = 0; i < m - 1; i++)
                cin >> x[i];
        for (int i = 0; i < n - 1; i++)
            cin >> p[i];
        for (auto& x : q)
            cin >> x;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m - 1; j++) {
                int id = getId(i, j, m);
                US.sum[id] = w[i][j] - w[i][j + 1] + v[i][j] - v[i + 1][j];
                US.bad[id] = j == 0 && p[i][j] == '0' || j + 1 == m - 1 && p[i][j + 1] == '0' ||
                             i == 0 && q[i][j] == '0' || i + 1 == n - 1 && q[i + 1][j] == '0';
            }
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m - 1; j++) {
                int id = getId(i, j, m);
                if (j + 1 < m - 1 && p[i][j + 1] == '0')
                    US.unionSet(id, getId(i, j + 1, m));
                if (i + 1 < n - 1 && q[i + 1][j] == '0')
                    US.unionSet(id, getId(i + 1, j, m));
            }
        ll res = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m - 1; j++) {
                int id = getId(i, j, m);
                if (US.getPar(id) == id && !US.bad[id])
                    res += max(0ll, US.sum[id]);
            }
        cout << res << "\n";
    }
    return 0;
}
