#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

int getWays(int t0, int tx, int need0, const vector<int>& fac, const vector<int>& ifac) {
    return C(tx, need0 - t0, fac, ifac);
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
        string s;
        cin >> s;
        s = " " + s;
        vector val(k - 1, -1);
        array<int, 2> mx{};
        for (int i = 0; i < mx.size(); i++)
            while (mx[i] + 1 <= n && s[mx[i] + 1] != 1 - i + '0')
                mx[i]++;
        vector<int> fac(n + 1), ifac(n + 1);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = static_cast<ll>(i) * fac[i - 1] % mod;
            ifac[i] = Inv(fac[i]);
        }
        for (int i = 0; i < k - 1; i++) {
            int ind = n - i;
            if (s[ind] != '?')
        }
    }
    return 0;
}
