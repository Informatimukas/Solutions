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

int getWays(const vector<int>& a) {
    vector<int> has(a.size());
    vector<int> fac(a.size() + 1), ifac(a.size() + 1);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < fac.size(); i++) {
        fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
        ifac[i] = Inv(fac[i]);
    }
    for (int i = 0; i < has.size(); i++)
        has[i] = max(0, static_cast<int>(a.size()) - 2 * i);
    int tk = 0, res = 1;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (has[i] - tk < a[i])
            return 0;
        res = static_cast<ll>(res) * C(has[i] - tk, a[i], fac, ifac) % mod;
        tk += a[i];
    }
    return tk == a.size() ? res : 0;
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << getWays(a) << "\n";
    }
    return 0;
}
