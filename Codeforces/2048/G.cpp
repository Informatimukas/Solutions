#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

struct matrix {
    int a, b;
    matrix(int gb = 0): a(1), b(gb) {}
    matrix operator*(const matrix& oth) const {
        matrix r;
        r.a = (static_cast<ll>(a) * oth.a + static_cast<ll>(b) * oth.b) % mod;
        r.b = (static_cast<ll>(a) * oth.b + static_cast<ll>(b) * oth.a) % mod;
        return r;
    }
};

int SolveB(int x, int m) {
    matrix res, a(x);
    while (m) {
        if (m & 1)
            res = res * a;
        m >>= 1;
        a = a * a;
    }
    return (res.a - 1 - res.b + mod) % mod;
}

int toPower(int a, ll p) {
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, m, v;
        cin >> n >> m >> v;
        int ca = 1;
        int res = 0;
        for (int a = 1; a <= n; a++) {
            ca = static_cast<ll>(ca) * (n - (a - 1)) % mod * Inv(a) % mod;
            ca = (mod - ca) % mod;
            int add = 0;
            for (int d = 1; d <= v; d++) {
                int y = static_cast<ll>(toPower(d, m * a)) * toPower(v, (n - a) * m) % mod;
                int bot = static_cast<ll>(toPower(d, a)) * toPower(v, n - a) % mod;
                int x = static_cast<ll>(toPower(v - d + 1, n - a)) * Inv(bot) % mod;
                add = (add + static_cast<ll>(y) * SolveB(x, m)) % mod;
            }
            res = (res + static_cast<ll>(ca) * add) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
