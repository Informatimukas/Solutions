#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Traverse(int v, int p, int n, int k, const vector<vector<int>>& neigh, vector<int>& cnt) {
    cnt[v] = 1;
    ll res = 1;
    for (auto& u : neigh[v]) {
        if (u == p)
            continue;
        res += Traverse(u, v, n, k, neigh, cnt);
        cnt[v] += cnt[u];
        if (n - cnt[u] >= k)
            res += cnt[u];
    }
    if (cnt[v] >= k)
        res += n - cnt[v];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector neigh(n + 1, vector<int>());
        vector cnt(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        cout << Traverse(1, 0, n, k, neigh, cnt) << "\n";
    }
    return 0;
}
