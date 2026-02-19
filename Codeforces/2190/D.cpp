#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

struct node {
    vector<int> neigh;
    int comp{0}, par{0}, siz{0};
    ll res{0};
};

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1ll)
            res = res * a % mod;
        p >>= 1ll;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); }

void Traverse(vector<node>& nodes, int v, int cur) {
    nodes[v].comp = cur;
    nodes[v].siz = 1;
    for (auto u : nodes[v].neigh) {
        if (nodes[v].par == u)
            continue;
        nodes[u].par = v;
        Traverse(nodes, u, cur);
        nodes[v].siz += nodes[u].siz;
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
        vector<node> nodes(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].neigh.push_back(b);
            nodes[b].neigh.push_back(a);
        }
        vector<int> sizes;
        Traverse(nodes, n, 1);
        sizes.push_back(nodes[n].siz);
        for (int i = 1; i <= n; i++)
            if (!nodes[i].comp) {
                Traverse(nodes, i, sizes.size() + 1);
                sizes.push_back(nodes[i].siz);
            }
        ll res = 1;
        if (sizes.size() > 1) {
            for (int i = 0; i < sizes.size() - 2; i++)
                res = res * n % mod;
            for (auto el : sizes)
                res = res * el % mod;
        }
        if (nodes[n - 1].comp == 1) {
            int v = n - 1;
            while (nodes[v].par != n)
                v = nodes[v].par;
            nodes[v].res = res;
        } else {
            ll inv = Inv(nodes[n].siz), invn = Inv(n);
            for (auto u : nodes[n].neigh)
                nodes[u].res = res * nodes[u].siz % mod * inv % mod;
            for (int i = 1; i < n; i++)
                if (nodes[i].comp != 1)
                    if (nodes[i].comp == nodes[n - 1].comp)
                        nodes[i].res = res * invn % mod * inv % mod
                        * Inv(sizes[nodes[i].comp - 1]) % mod
                        * (nodes[n].siz + sizes[nodes[i].comp - 1]) % mod;
                    else nodes[i].res = res * invn % mod * inv % mod;
        }
        for (int i = 1; i < n; i++)
            cout << nodes[i].res << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
