#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;
using lli = pair<ll, int>;

constexpr int mod = 998244353;
constexpr ll Inf = 4000000000000000000ll;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1)
            res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void solveVertex(int v, const vector<vector<ii>>& neigh, vector<ll>& dist, vector<int>& ways) {
    dist[v] = 0;
    ways[v] = 1;
    priority_queue<lli, vector<lli>, greater<>> Q;
    Q.emplace(dist[v], v);
    while (!Q.empty()) {
        v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (dist[v] != d)
            continue;
        for (auto& [u, c] : neigh[v]) {
            ll cand = d + c;
            if (cand < dist[u]) {
                dist[u] = cand;
                ways[u] = 1;
                Q.emplace(dist[u], u);
            } else if (cand == dist[u])
                ways[u] = (ways[u] + 1) % mod;
        }
    }
}

int solveOne(const vector<vector<ii>>& neigh, int st, const vector<int>& oways) {
    vector dist(neigh.size(), Inf);
    vector ways(neigh.size(), 0);
    dist[1] = 0;
    ways[1] = st;
    priority_queue<lli, vector<lli>, greater<>> Q;
    Q.emplace(dist[1], 1);
    while (!Q.empty()) {
        int v = Q.top().second;
        ll d = Q.top().first;
        Q.pop();
        if (dist[v] != d)
            continue;
        int w = static_cast<ll>(ways[v]) * Inv(oways[v]) % mod;
        if (v == 2)
            return w;
        for (auto& [u, c] : neigh[v]) {
            ll cand = d + c;
            if (cand < dist[u]) {
                dist[u] = cand;
                ways[u] = w;
                Q.emplace(dist[u], u);
            } else if (cand == dist[u])
                ways[u] = (ways[u] + w) % mod;
        }
    }
    return -1;
}

int getWays(ll d1, int w1, ll d2, int w2) {
    if (d1 > d2) {
        swap(d1, d2);
        swap(w1, w2);
    }
    if (d1 < d2)
        return w1;
    return (w1 + w2) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector neigh(n + 1, vector<ii>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        neigh[a].emplace_back(b, c);
        neigh[b].emplace_back(a, c);
    }
    vector dist1(neigh.size(), Inf);
    vector ways1(neigh.size(), 0);
    vector dist2(neigh.size(), Inf);
    vector ways2(neigh.size(), 0);
    solveVertex(1, neigh, dist1, ways1);
    solveVertex(2, neigh, dist2, ways2);
    int tot = 1;
    for (int i = 1; i <= n; i++)
        tot = static_cast<ll>(tot) *
            getWays(dist1[i], ways1[i], dist2[i], ways2[i]) % mod;
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dist1[i] <= dist2[i])
            for (auto& [u, c] : neigh[i])
                if (dist2[u] < dist1[u] && dist1[i] + c + dist2[u] == dist1[2]) {
                    int cur = static_cast<ll>(tot) *
                        Inv(getWays(dist1[i], ways1[i], dist2[i], ways2[i])) % mod *
                            Inv(getWays(dist1[u], ways1[u], dist2[u], ways2[u])) % mod *
                                ways1[i] % mod * ways2[u] % mod;
                    res = (res + cur) % mod;
                }
    cout << res << "\n";
    return 0;
}