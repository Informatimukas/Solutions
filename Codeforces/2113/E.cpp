#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

constexpr int Inf = 1000000000;

void Prepare(int v, const vector<vector<int>>& neigh, vector<int>& L, vector<int>& P) {
    for (auto& u: neigh[v]) {
        if (u == P[v]) continue;
        P[u] = v;
        L[u] = L[v] + 1;
        Prepare(u, neigh, L, P);
    }
}

int getLength(int a, int b, const vector<int>& P, const vector<int>& L) {
    int res = 0;
    while (a != b) {
        if (L[a] < L[b])
            swap(a, b);
        a = P[a];
        res++;
    }
    return res;
}


void markForbidden(int a, int b, const vector<int>& P, const vector<int>& L,
    vector<vector<int>>& forb) {
    int l = 1, r = getLength(a, b, P, L) + 1;
    while (a != b)
        if (L[a] >= L[b]) {
            forb[a].push_back(l++);
            a = P[a];
        } else {
            forb[b].push_back(r--);
            b = P[b];
        }
    forb[a].push_back(l);
}

void Check(int v, int lef, int rig,
    vector<int>& dist, const vector<int>& forb,
    vector<vector<ii>>& queues) {
    auto i = distance(forb.begin(), ranges::lower_bound(forb, lef));
    for (; i < dist.size() && lef <= rig; i++) {
        if (lef < forb[i] && lef < dist[i]) {
            dist[i] = lef;
            queues[lef].emplace_back(v, i);
        }
        lef = forb[i] + 1;
    }
}

int Solve(int x, int y,
    const vector<vector<int>>& neigh, vector<vector<int>>& forb) {
    vector dist(forb.size(), vector<int>());
    for (int i = 0; i < forb.size(); i++) {
        ranges::sort(forb[i]);
        forb[i].push_back(Inf);
        dist[i].resize(forb[i].size(), Inf);
    }
    vector queues(2 * neigh.size(), vector<ii>());
    Check(x, 1, 1, dist[x], forb[x], queues);
    for (int d = 0; d < queues.size(); d++)
        for (auto& p : queues[d]) {
            if (d != dist[p.first][p.second])
                continue;
            if (p.first == y)
                return d;
            int nd = forb[p.first][p.second];
            for (auto& u: neigh[p.first])
                Check(u, d + 1, nd, dist[u], forb[u], queues);
        }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector forb(n + 1, vector<int>());
        vector neigh(n + 1, vector<int>());
        vector L(n + 1, 0), P(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        Prepare(x, neigh, L, P);
        while (m--) {
            int a, b;
            cin >> a >> b;
            markForbidden(a, b, P, L, forb);
        }
        cout << Solve(x, y, neigh, forb) << "\n";
    }
    return 0;
}
