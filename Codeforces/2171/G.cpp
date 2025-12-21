#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000003;

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); }

ll C(ll n, ll k, const vector<ll>& fac, const vector<ll>& ifac) {
    ll res = 1;
    while (n || k) {
        ll remn = n % mod;
        ll remk = k % mod;
        if (remk > remn)
            return 0;
        res = res * fac[remn] % mod * ifac[remk] % mod * ifac[remn - remk] % mod;
        n /= mod;
        k /= mod;
    }
    return res;
}

bool canReduce(const vector<ll>& a, const vector<ll>& b) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] > b[i] / 2)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> fac(mod), ifac(mod);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < mod; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = Inv(fac[i]);
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto& x : a)
            cin >> x;
        for (auto& x : b)
            cin >> x;
        ll need = 0;
        ll ways = 1;
        while (canReduce(a, b)) {
            ll all = 0;
            for (auto& x : b) {
                if (x % 2) {
                    ways = ways * C(++all, 1, fac, ifac) % mod;
                    ++need;
                }
                x /= 2;
            }
            ++need;
        }
        ll all = 0;
        for (int i = 0; i < n; i++) {
            all += b[i] - a[i];
            need += b[i] - a[i];
            ways = ways * C(all, b[i] - a[i], fac, ifac) % mod;
        }
        cout << need << " " << ways << "\n";
    }
    return 0;
}
