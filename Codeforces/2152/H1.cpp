#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;
using ii = pair<int, int>;

llll Solve(const vector<vector<ii>>& neigh, int v, int p, int pw, int target) {
    ll need = target - pw, sum = 0, best = 0;
    for (auto& [u, w] : neigh[v]) {
        if (u == p)
            continue;
        auto [gotSum, gotBest] = Solve(neigh, u, v, w, target);
        sum += gotSum;
        best += gotBest;
    }
    need += best;
    ll mySum = max(sum, need);
    ll myBest = max(best, mySum - pw);
    return {mySum, myBest};
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
        vector<vector<ii>> neigh(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            neigh[u].emplace_back(v, w);
            neigh[v].emplace_back(u, w);
        }
        int q;
        cin >> q;
        while (q--) {
            int l;
            cin >> l;
            cout << Solve(neigh, 1, 0, 0, l).first << "\n";
        }
    }
    return 0;
}
