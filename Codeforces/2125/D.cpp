#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using segment = array<int, 4>;

constexpr int mod = 998244353;

int toPower(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) res = static_cast<ll>(res) * a % mod;
        p >>= 1; a = static_cast<ll>(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<segment> seq;
    while (n--) {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        int prob = static_cast<ll>(p) * Inv(q) % mod;
        seq.push_back({l, r, prob});
    }
    ranges::sort(seq);
    int globalMult = 1;
    vector cur(m + 2, 0);
    cur[1] = 1;
    for (auto& s : seq) {
        int my = static_cast<ll>(globalMult) * cur[s[0]] % mod;
        globalMult = static_cast<ll>(globalMult) * (1 - s[2] + mod) % mod;
        int add = static_cast<ll>(my) * s[2] % mod * Inv(globalMult) % mod;
        cur[s[1] + 1] = (cur[s[1] + 1] + add) % mod;
    }
    int ans = static_cast<ll>(globalMult) * cur[m + 1] % mod;
    cout << ans << "\n";
    return 0;
}
