#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lli = pair<ll, int>;

constexpr int mod = 1000000007;
constexpr int Maxp = 70;

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

int C(ll n, int k) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    int res = 1;
    int dv = 1;
    for (int i = 1; i <= k; i++) {
        res = (n + 1ll - i) % mod * res % mod;
        dv = static_cast<ll>(dv) * i % mod;
    }
    return static_cast<ll>(res) * Inv(dv) % mod;
}

int Solve(const vector<lli>& seq, int lvl, ll candA, ll A, int ways, const vector<int>& vals) {
    if (lvl >= seq.size())
        return candA <= A ? ways : 0;
    int res = 0;
    for (int i = 0; i <= seq[lvl].second; i++) {
        res = (res + Solve(seq, lvl + 1, candA, A,
            static_cast<ll>(ways) * vals[i] % mod * vals[seq[lvl].second - i] % mod,
            vals)) % mod;
        candA *= seq[lvl].first;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        ll n, a, b;
        cin >> n >> a >> b;
        vector<int> vals(Maxp);
        for (int i = 0; i < Maxp; i++)
            vals[i] = C(n - 1 + i, i);
        vector<lli> seq;
        for (ll i = 2; i * i <= b; i++)
            if (b % i == 0) {
                int cnt = 0;
                while (b % i == 0) {
                    b /= i;
                    cnt++;
                }
                seq.emplace_back(i, cnt);
            }
        if (b > 1)
            seq.emplace_back(b, 1);
        cout << "Case #" << tc << ": " << Solve(seq, 0, 1ll, a, 1, vals) << "\n";
    }
    return 0;
}