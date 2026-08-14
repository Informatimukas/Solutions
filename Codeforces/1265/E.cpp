#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

constexpr ll mod = 998244353;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p)
        cin >> x;
    vector<llll> res(n + 1, {0, 0});
    ll inv100 = Inv(100);
    for (int i = n - 1; i >= 0; i--) {
        ll good = p[i] * inv100 % mod;
        res[i].first = (res[i].first + good * res[i + 1].first) % mod;
        res[i].second = (res[i].second + good * res[i + 1].second) % mod;
        ll bad = (100 - p[i]) * inv100 % mod;
        res[i].first = (res[i].first + bad) % mod;
        res[i].second = (res[i].second + 1) % mod;
    }
    ll ans = res[0].second * Inv((1 - res[0].first + mod) % mod) % mod;
    cout << ans << "\n";
    return 0;
}
