#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;

struct node {
    int xr{0};
    int a;
    vector<int> neigh;
};

int getGood(const vector<int>& seq, int x) {
    auto it = ranges::find(seq, x);
    if (it == seq.end())
        return -1;
    return distance(seq.begin(), it);
}

vector<ll> Solve(vector<node>& nodes, int v, int p,
    const vector<int>& good, const vector<int>& vals) {
    vector<ll> my(1 << good.size(), 0);
    my[0] = 1;
    nodes[v].xr = nodes[v].a;
    for (auto u : nodes[v].neigh) {
        if (u == p)
            continue;
        vector<ll> nw(1 << good.size(), 0);
        auto got = Solve(nodes, u, v, good, vals);
        nodes[v].xr ^= nodes[u].xr;
        for (int i = 0; i < my.size(); i++)
            for (int j = 0; j < got.size(); j++)
                nw[i ^ j] = (nw[i ^ j] + my[i] * got[j]) % mod;
        for (int j = 0; j < got.size(); j++) {
            int lft = nodes[u].xr ^ vals[j];
            int ind = getGood(good, lft);
            if (ind == -1)
                continue;
            int nj = j ^ (1 << ind);
            for (int i = 0; i < my.size(); i++)
                nw[i ^ nj] = (nw[i ^ nj] + my[i] * got[j]) % mod;
        }
        my = std::move(nw);
    }
    return my;
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
        vector<node> nodes(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].a;
        vector<int> good(k);
        for (auto& x : good)
            cin >> x;
        vector vals(1 << k, 0);
        for (int i = 0; i < 1 << k; i++)
            for (int j = 0; j < k; j++)
                if (i & 1 << j)
                    vals[i] ^= good[j];
        ll res = 0;
        auto got = Solve(nodes, 1, 0, good, vals);
        for (int i = 0; i < got.size(); i++) {
            int lft = nodes[1].xr ^ vals[i];
            if (getGood(good, lft) != -1)
                res = (res + got[i]) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
