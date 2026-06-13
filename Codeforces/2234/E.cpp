#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 500005;
constexpr ll mod = 1000000007;

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1ll)
            res = res * a % mod;
        p >>= 1ll;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); }

ll C(int n, int k, const vector<ll>& fac, const vector<ll>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

ll Solve(const vector<ll>& a, int lef, int rig, int bigger, const vector<ll>& fac, const vector<ll>& ifac) {
    ll res = 1;
    if (lef > rig)
        return res;
    int cur = lef;
    while (cur <= rig) {
        if (a[cur] % (bigger + 1))
            return 0;
        ll tk = a[cur] / (bigger + 1) - 1;
        if (cur + tk > rig)
            return 0;
        res = res * Solve(a, cur + 1, cur + tk, 0, fac, ifac) % mod *
            C(bigger + tk, tk, fac, ifac) % mod;
        bigger += tk + 1;
        cur += tk + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> fac(Maxn), ifac(Maxn);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = i * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        cout << Solve(a, 0, n - 1, 0, fac, ifac) << "\n";
    }
    return 0;
}
