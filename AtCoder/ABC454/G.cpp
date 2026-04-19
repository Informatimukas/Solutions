#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using hash_table = unordered_map<int, int, custom_hash>;
using ll = long long;

constexpr ll mod = 998244353;

struct pos {
    hash_table M;
    ll m{0}, k{0};
    void Add(int key, int value) {
        auto it = M.find(key);
        if (it == M.end())
            M.emplace(key, value);
        else {
            value += it->second;
            it->second = value;
        }
        if (value > m) {
            m = value;
            k = 0;
        }
        if (value == m)
            k++;
    }
};

pos Solve(int v, const vector<vector<int>>& neigh, const vector<ll>& c, ll& res) {
    pos my;
    my.Add(c[v], 1);
    for (auto u : neigh[v]) {
        auto got = Solve(u, neigh, c, res);
        if (my.M.size() < got.M.size())
            swap(my, got);
        for (auto& [key, value] : got.M)
            my.Add(key, value);
    }
    res = (res + (my.m ^ v) * (my.k ^ v)) % mod;
    return my;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll seed;
    int m;
    ll F;
    cin >> n >> seed >> m >> F;
    vector<ll> q(m + 1);
    vector<ll> d(m + 1);
    for (int i = 2; i <= m; i++)
        cin >> q[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i];
    vector<ll> p(n + 1);
    vector<ll> c(n + 1);
    auto state = seed;
    for (int i = 2; i <= n; i++)
        if (i <= m)
            p[i] = q[i];
        else {
            p[i] = (state % (i - 1)) + 1;
            state = (state * 1103515245ll + 12345ll) % (1ll << 31ll);
        }
    for (int i = 1; i <= n; i++)
        if (i <= m)
            c[i] = d[i];
        else {
            c[i] = (state % F) + 1;
            state = (state * 1103515245ll + 12345ll) % (1ll << 31ll);
        }
    vector neigh(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
        neigh[p[i]].push_back(i);
    ll res = 0ll;
    Solve(1, neigh, c, res);
    cout << res << "\n";
    return 0;
}
