#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;

int Solve(int v, int forb, vector<set<int>>& neigh) {
    while (!neigh[v].empty() && *neigh[v].begin() == forb)
        neigh[v].erase(neigh[v].begin());
    return neigh[v].empty() ? 1 : 1 + Solve(*neigh[v].begin(), v, neigh);
}

int Solve(const vector<vector<int>>& neigh, const vector<int>& fac) {
    vector sneigh(neigh.size(), set<int>());
    int res = 2;
    for (int i = 1; i < neigh.size(); i++)
        if (neigh[i].size() >= 2) {
            int oth = 0;
            for (auto& u : neigh[i])
                if (neigh[u].size() >= 2) {
                    sneigh[i].insert(u);
                    sneigh[u].insert(i);
                } else oth++;
            res = static_cast<ll>(res) * fac[oth] % mod;
        }
    int need = 0, fir = 0;
    for (int i = 1; i < sneigh.size(); i++) {
        if (sneigh[i].size() >= 3)
            return 0;
        if (sneigh[i].empty())
            continue;
        need++;
        if (sneigh[i].size() == 1)
            fir = i;
    }
    if (need == 0)
        return res;
    return Solve(fir, 0, sneigh) == need? 2 * res % mod: 0;
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
        vector neigh(n + 1, vector<int>());
        vector<int> fac(n + 1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
        cout << Solve(neigh, fac) << "\n";
    }
    return 0;
}
