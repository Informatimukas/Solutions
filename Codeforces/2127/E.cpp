#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Fill(int v, int p, int col, vector<int>& C, const vector<vector<int>>& neigh) {
    C[v] = col;
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        Fill(u, v, col, C, neigh);
    }
}

ll Solve(int v, int p, const vector<int>& W, vector<int>& C,
    const vector<vector<int>>& neigh, vector<set<int>>& my) {
    ll res = 0;
    set<int> sam;
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        res += Solve(u, v, W, C, neigh, my);
        if (my[v].size() < my[u].size())
            swap(my[v], my[u]);
        for (auto& x : my[u])
            if (!my[v].insert(x).second)
                sam.insert(x);
    }
    if (sam.size() >= 2 || sam.size() == 1 && C[v] != 0 && C[v] != *sam.begin())
        res += W[v];
    if (C[v] == 0)
        if (!sam.empty()) C[v] = *sam.begin();
        else if (!my[v].empty()) C[v] = *my[v].begin();
    if (C[v] != 0) {
        my[v].insert(C[v]);
        for (auto& u : neigh[v]) {
            if (u == p) continue;
            if (C[u] == 0)
                Fill(u, v, C[v], C, neigh);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> W(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> W[i];
        vector<int> C(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> C[i];
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        vector my(n + 1, set<int>());
        ll res = Solve(1, 0, W, C, neigh, my);
        if (C[1] == 0)
            Fill(1, 0, 1, C, neigh);
        cout << res << "\n";
        for (int i = 1; i <= n; i++)
            cout << C[i] << (i + 1 <= n? ' ': '\n');
    }
    return 0;
}