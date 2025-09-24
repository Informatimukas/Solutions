#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int mod = 998244353;

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

void addBIT(vector<ii>& BIT, int x, int val1, int val2) {
    for (int i = x; i < BIT.size(); i += i & -i) {
        BIT[i].first = (BIT[i].first + val1) % mod;
        BIT[i].second = (BIT[i].second + val2) % mod;
    }
}

void addBITInterval(vector<ii>& BIT, int lef, int rig, int a, int b, int val) {
    int res2 = static_cast<ll>(val) * b % mod;
    int res1 = static_cast<ll>(val) * a % mod;
    res1 = (res1 - static_cast<ll>(lef) * res2 % mod + mod) % mod;
    addBIT(BIT, lef, res1, res2);
    addBIT(BIT, rig + 1, (mod - res1) % mod, (mod - res2) % mod);
}

int getBIT(const vector<ii>& BIT, int x) {
    int res1 = 0, res2 = 0;
    for (int i = x; i > 0; i -= i & -i) {
        res1 = (res1 + BIT[i].first) % mod;
        res2 = (res2 + BIT[i].second) % mod;
    }
    return (res1 + static_cast<ll>(res2) * x) % mod;
}

void Add(vector<ii>& BIT, int lef, int rig, int x, int val) {
    if (val == 0)
        return;
    if (x == 0)
        return;
    int n = rig - lef + 1;
    x = min(x, n - x + 1);
    if (2 * x == n + 1) {
        addBITInterval(BIT, lef, lef + x - 1, 1, 1, val);
        addBITInterval(BIT, lef + x, rig, x - 1, mod - 1, val);
        return;
    }
    addBITInterval(BIT, lef, lef + x - 1, 1, 1, val);
    addBITInterval(BIT, rig - x + 1, rig, x, mod - 1, val);
    if (lef + x <= rig - x)
        addBITInterval(BIT, lef + x, rig - x, x, 0, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector vals(n + 1, 0);
        vector BIT(n + 1, ii{0, 0});
        int lim = 2 * (n + 1);
        vector<int> fac(lim), ifac(lim);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < fac.size(); i++) {
            fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
            ifac[i] = Inv(fac[i]);
        }
        Add(BIT, 1, n, 1, n);
        for (int i = 2; i <= n; i++)
            for (int a = 0; a < 2; a++)
                for (int b = 0; b < 2; b++)
                    if ((a + b + i - 2) % 2 == n % 2) {
                        int rem = (n - a - b - (i - 2)) / 2;
                        if (a == 0) rem--;
                        if (b == 0) rem--;
                        int ways = C(rem + i - 1, i - 1, fac, ifac);
                        if (ways == 0) continue;
                        if (a == 0)
                            Add(BIT, 1, n - (i - 1), 1, 2 * ways % mod);
                        if (b == 0)
                            Add(BIT, i, n, 1, 2 * ways % mod);
                        Add(BIT, 1 + (a == 0), n - (b == 0), i - (a == 0) - (b == 0), ways);
                        ways = 2ll * C(rem + i - 1, i, fac, ifac) % mod;
                        Add(BIT, 1, n, i, ways);
                    }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            res = (res + static_cast<ll>(a) * getBIT(BIT, i)) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}
