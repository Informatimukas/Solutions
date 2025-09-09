#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

struct state {
    ll prob, leaves, pairLeaves;
    state(ll gprob = 0, ll gleaves = 0, ll gpairLeaves = 0):
        prob(gprob), leaves(gleaves), pairLeaves(gpairLeaves) {}
    state operator+(const state& oth) const {
        return {(prob + oth.prob) % mod,
            (leaves + oth.leaves) % mod,
            (pairLeaves + oth.pairLeaves) % mod};
    }
    state operator*(const state& oth) const {
        ll nprob = prob * oth.prob % mod;
        ll nleaves = (leaves * oth.prob + prob * oth.leaves) % mod;
        ll npairLeaves = (pairLeaves * oth.prob + prob * oth.pairLeaves + leaves * oth.leaves) % mod;
        return {nprob, nleaves, npairLeaves};
    }
};

using StateTable = array<array<state, 2>, 2>;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) res = static_cast<ll>(res) * a % mod;
        p >>= 1;
        a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

StateTable Solve(int v, int p, const vector<vector<int>>& neigh,
    const vector<array<int, 2>>& prob) {
    vector<pair<StateTable, int>> states;
    for (auto& u : neigh[v]) {
        if (u == p) continue;
        states.emplace_back(Solve(u, v, neigh, prob), u);
    }
    StateTable res;
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++) {
            array<state, 3> dp{};
            int ind = b == 0 ? 2 : a == 0 ? 0 : 1;
            dp[ind] = {1, 0, 0};
            for (auto& [st, u] : states) {
                for (int j = dp.size() - 1; j >= 0; j--) {
                    auto cur = dp[j];
                    dp[j] = {0, 0, 0};
                    for (int k = 0; k < 2; k++) {
                        int nj = min(2, j + k);
                        state addState = {
                            prob[u][k] * st[b][k].prob % mod,
                            prob[u][k] * st[b][k].leaves % mod,
                            prob[u][k] * st[b][k].pairLeaves % mod
                        };
                        dp[nj] = dp[nj] + cur * addState;
                    }
                }
            }
            for (int j = 0; j < dp.size(); j++)
                if (j == 1)
                    res[a][b] = res[a][b] + dp[j] * state{1, 1, 0};
                else res[a][b] = res[a][b] + dp[j];
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector prob(n + 1, array<int, 2>());
        for (int i = 1; i <= n; i++) {
            int p, q;
            cin >> p >> q;
            int invq = Inv(q);
            prob[i][0] = static_cast<ll>(p) * invq % mod;
            prob[i][1] = static_cast<ll>(q - p) * invq % mod;
        }
        vector neigh(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            neigh[a].push_back(b);
            neigh[b].push_back(a);
        }
        int res = 0;
        auto got = Solve(1, 0, neigh, prob);
        for (int j = 0; j < 2; j++)
            res = (res + got[0][j].pairLeaves * prob[1][j]) % mod;
        cout << res << "\n";
    }
    return 0;
}