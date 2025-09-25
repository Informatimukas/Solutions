#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 400005;
constexpr int mod = 1000000007;

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

int C(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return static_cast<ll>(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int getWays(int pl, int r, const vector<int>& fac, const vector<int>& ifac) {
    return C(r + pl - 1, pl - 1, fac, ifac);
}

int getWaysAll(int pl, int r, const vector<int>& fac, const vector<int>& ifac) {
    return C(r + pl - 1, pl, fac, ifac);
}

int getFirst(int n, int m, const vector<int>& fac, const vector<int>& ifac) {
    int res = 0;
    for (int x = 1; x <= m; x++)
        for (int bad = 0; x + (x + 1) * bad <= m; bad++) {
            int ways = getWaysAll(n - 1, m - x - (x + 1) * bad, fac, ifac);
            ways = (ways -
                getWaysAll(n - 1, m - x - x - (x + 1) * bad, fac, ifac) + mod) % mod;
            ways = (ways - static_cast<ll>(x) *
                getWays(n - 1, m - x - (x + 1) * (bad + 1), fac, ifac) % mod + mod) % mod;
            ways = static_cast<ll>(ways) * C(n - 2, bad, fac, ifac) % mod;
            if (bad % 2)
                ways = (mod - ways) % mod;
            res = (res + ways) % mod;
        }
    return res;
}

int getLast(int n, int m, const vector<int>& fac, const vector<int>& ifac) {
    int res = 0;
    for (int x = 1; x <= m; x++)
        for (int bad = 0; x + (x + 1) * bad <= m; bad++) {
            int ways = getWays(n - 1, m - x - (x + 1) * bad, fac, ifac);
            ways = static_cast<ll>(ways) * C(n - 1, bad, fac, ifac) % mod;
            if (bad % 2)
                ways = (mod - ways) % mod;
            res = (res + static_cast<ll>(ways) * x) % mod;
        }
    return res;
}

int getSame(int n, int m, const vector<int>& fac, const vector<int>& ifac) {
    int res = 0;
    for (int x = 1; x <= m; x++)
        for (int bad = 0; x + x + (x + 1) * bad <= m; bad++) {
            int ways = getWays(n - 2, m - x - x - (x + 1) * bad, fac, ifac);
            ways = static_cast<ll>(ways) * C(n - 2, bad, fac, ifac) % mod * (n - 1) % mod;
            if (bad % 2)
                ways = (mod - ways) % mod;
            res = (res + static_cast<ll>(ways) * x) % mod;
        }
    return res;
}

int getThree(int n, int m, const vector<int>& fac, const vector<int>& ifac) {
    int res = 0;
    for (int x = 1; x <= m; x++)
        for (int bad = 0; x + x + (x + 1) * bad <= m; bad++) {
            int ways = getWaysAll(n - 2, m - x - x - (x + 1) * bad, fac, ifac);
            ways = (ways -
                getWaysAll(n - 2, m - 3 * x - (x + 1) * bad, fac, ifac) + mod) % mod;
            ways = (ways - static_cast<ll>(x) *
                getWays(n - 2, m - 2 * x - (x + 1) * (bad + 1), fac, ifac) % mod + mod) % mod;
            ways = static_cast<ll>(ways) * (n - 2) % mod *
                C(n - 3, bad, fac, ifac) % mod;
            if (bad % 2)
                ways = (mod - ways) % mod;
            res = (res + ways) % mod;
        }
    return res;
}

int getClose(int n, int m, const vector<int>& fac, const vector<int>& ifac) {
    int res = 0;
    for (int x = 1; x <= m; x++)
        for (int bad = 0; x + x + (x + 1) * bad <= m; bad++) {
            int ways = getWays(n - 2, m - x - x - (x + 1) * bad, fac, ifac);
            ways = static_cast<ll>(ways) * C(n - 2, bad, fac, ifac) % mod;
            if (bad % 2)
                ways = (mod - ways) % mod;
            res = (res + static_cast<ll>(ways) * x) % mod;
        }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> fac(Maxn), ifac(Maxn);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = static_cast<ll>(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int res = (getLast(n, m, fac, ifac) + getSame(n, m, fac, ifac)) % mod;
        res = (res - getFirst(n, m, fac, ifac) + mod) % mod;
        res = (res - getThree(n, m, fac, ifac) + mod) % mod;
        res = (res - getClose(n, m, fac, ifac) + mod) % mod;
        cout << res << "\n";
    }
    return 0;
}
