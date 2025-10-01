#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

ll Solve(int v, const vector<vector<int>>& neigh, int& rem) {
    vector<int> big;
    for (auto& u : neigh[v])
        if (!neigh[u].empty())
            big.push_back(u);
    if (big.size() >= 2)
        return 0;
    ll res = big.empty() ? 1 : Solve(big[0], neigh, rem);
    for (auto& u : neigh[v])
        if (neigh[u].empty())
            res = res * rem-- % mod;
    rem--;
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
        vector neigh(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            neigh[p].push_back(i);
        }
        int rem = n;
        cout << Solve(1, neigh, rem) << "\n";
    }
    return 0;
}
