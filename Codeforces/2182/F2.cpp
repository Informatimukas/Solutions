#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;
constexpr int Maxn = 600005;
constexpr int Maxb = 62;

vector<ll> fac(Maxn), ifac(Maxn), pw2(Maxn);

ll toPower(ll a, int p) {
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

void updateWays(array<ll, Maxb>& arr, int cnt) {
    for (int i = 0; i < Maxb; i++) {
        arr[i] = C(cnt, i);
        if (i)
            arr[i] = (arr[i] + arr[i - 1]) % mod;
    }
}

void updateNext(array<ll, Maxb>& nxt, const array<int, Maxb>& cnt) {
    ll cur = 0;
    for (int i = 0; i < Maxb; i++) {
        nxt[i] = cur;
        cur = (cur + cnt[i]) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = ifac[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        fac[i] = i * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
        pw2[i] = 2 * pw2[i - 1] % mod;
    }
    array<int, Maxb> cnt{};
    array<array<ll, Maxb>, Maxb> ways{};
    array<ll, Maxb> nxt{};
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }
    for (int i = 0; i < Maxb; i++)
        updateWays(ways[i], cnt[i]);
    updateNext(nxt, cnt);
    while (m--) {
        int typ;
        cin >> typ;
        if (typ <= 2) {
            int x;
            cin >> x;
            cnt[x] += typ == 1 ? 1 : -1;
            updateWays(ways[x], cnt[x]);
            updateNext(nxt, cnt);
        } else {
            ll x;
            cin >> x;
            array<int, Maxb> my{};
            for (int i = Maxb - 1; i >= 0; i--)
                while (x & 1ll << i) {
                    my[i]++;
                    x ^= 1ll << i;
                    x <<= 1ll;
                }
            ll bad = 0, cur = 1;
            for (int i = Maxb - 1; i >= 0; i--) {
                ll B = ways[i][my[i]];
                ll A = 0;
                if (my[i] > 0) {
                    A = ways[i][my[i] - 1];
                    B = (B - A + mod) % mod;
                }
                bad = (bad + cur * A % mod * pw2[nxt[i]]) % mod;
                cur = cur * B % mod;
            }
            ll res = (pw2[nxt[Maxb - 1]] - bad + mod) % mod;
            cout << res << "\n";
        }
    }
    return 0;
}
