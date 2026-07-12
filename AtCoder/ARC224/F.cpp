#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 60;
constexpr ll mod = 998244353;
constexpr ll inv2 = (mod + 1) / 2;
constexpr int Maxn = 200006;

vector<ll> fac(Maxn), ifac(Maxn);

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

ll C(int n, int k) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

bool Check(ll val, const vector<ll>& a, int k) {
    for (auto x : a | views::reverse) {
        if (k == 0)
            return false;
        ll sam = (val & x);
        if (sam == val)
            return true;
        k--;
        val ^= sam;
    }
    return false;
}

ll Solve(ll val, const vector<ll>& a, int k) {
    bool comp = false;
    ll sum = 0;
    ll res = val == 0;
    for (int i = a.size() - 1; i >= 0; i--) {
       /* if (k == 0)
            break;*/
        ll sam = (val & a[i]);
        if (sam == val) {
            k--;
            if (k < 0) break;
            if (!comp) {
                comp = true;
                for (int j = 0; j <= k; j++)
                    sum = (sum + C(i, j)) % mod;
            } else sum = (sum + C(i, k)) * inv2 % mod;
            res = (res + sum) % mod;
            k++;
            continue;
        }
        if (comp)
            sum = (sum - C(i, k) + mod) * inv2 % mod;
        k--;
        val ^= sam;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = i * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        ll mask = 0;
        for (int i = Maxb - 1; i >= 0; i--)
            if (Check(mask | (1ll << i), a, k))
                mask |= 1ll << i;
        ll rmask = 0;
        for (int i = 1; i <= k; i++)
            rmask |= a[a.size() - i];
        assert(mask == rmask);
        cout << Solve(mask, a, k) << "\n";
    }
    return 0;
}
