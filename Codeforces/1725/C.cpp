#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 300005;
constexpr int mod = 998244353;

vector<ll> fac(Maxn), ifac(Maxn);

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

ll C(int n, int k) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> seq(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        seq[i] += seq[i - 1];
    }
    ll all = seq[n];
    int sam = 0;
    int l = 1, r = 1;
    while (r <= n)
        if (2 * (seq[r] - seq[l]) < all)
            r++;
        else if (2 * (seq[r] - seq[l]) > all)
            l++;
        else {
            sam++;
            l++;
        }

    return 0;
}
