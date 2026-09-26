#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using lli = pair<ll, int>;

constexpr ll Inf = 1000000000000000000ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<vector<ii>> neigh(n + 2);
    vector<ll> sum(n + 2);
    for (int i = 2; i <= n + 1; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
        int v = i - 1, u = i == n + 1 ? 1 : i;
        neigh[v].emplace_back(u, a);
        neigh[u].emplace_back(v, a);
    }
    for (int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        neigh[i].emplace_back(n + 1, b);
        neigh[n + 1].emplace_back(i, b);
    }
    vector dist(n + 2, Inf);
    priority_queue<lli, vector<lli>, greater<>> Q;
    int v = n + 1;
    dist[v] = 0;
    Q.emplace(dist[v], v);
    while (!Q.empty()) {
        v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (dist[v] != d)
            continue;
        for (auto& [u, add] : neigh[v]) {
            ll cand = d + add;
            if (cand < dist[u]) {
                dist[u] = cand;
                Q.emplace(dist[u], u);
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        ll res;
        if (b == n + 1)
            res = dist[a];
        else {
            ll dif = sum[b] - sum[a];
            dif = min(dif, sum[n + 1] - dif);
            res = min(dist[a] + dist[b], dif);
        }
        cout << res << "\n";
    }
    return 0;
}
