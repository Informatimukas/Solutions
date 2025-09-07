#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

struct state {
    ll prob, leaves, pairLeaves;
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

        }
    }
    return 0;
}