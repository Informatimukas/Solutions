#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct pos {
    ll all{0};
    deque<ll> D;
};

ll Solve(pos& a, const pos& b) {
    ll res = 0;
    ll cura = a.all, curb = b.all;
    for (int i = 0; i < b.D.size(); i++) {
        res += i * (a.D[i] * )
    }
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
        vector<vector<int>> neigh(n + 1);
        while (m--) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
        }
        vector<int> best(n + 1);
        vector<vector<int>> tneigh(n + 1);
        best[n] = 0;
        for (int i = n - 1; i > 0; i--) {
            best[i] = best[i + 1] + 1;
            int p = i + 1;
            for (auto u : neigh[i])
                if (best[u] + 1 < best[i]) {
                    best[i] = best[u] + 1;
                    p = u;
                }
            tneigh[p].push_back(i);
        }

    }
    return 0;
}
