#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 1000000007;
constexpr int inv6 = 166666668;

ll iSqrt(ll x) {
    ll cand = sqrt(x);
    while (cand * cand > x)
        cand--;
    while ((cand + 1) * (cand + 1) <= x)
        cand++;
    return cand;
}

int sumK(int a2, int to, const vector<int>& sumb2) {
    return (static_cast<ll>(a2) * to % mod + sumb2[to]) % mod;
}

int sumK2(int a2, int to, const vector<int>& sumb2, const vector<int>& sumb4) {
    int a4 = static_cast<ll>(a2) * a2 % mod;
    return (static_cast<ll>(a4) * to % mod +
            2ll * a2 % mod * sumb2[to] % mod +
            sumb4[to]) % mod;
}

int sumK3(int a2, int to, const vector<int>& sumb2, const vector<int>& sumb4,
    const vector<int>& sumb6) {
    int a4 = static_cast<ll>(a2) * a2 % mod;
    int a6 = static_cast<ll>(a4) * a2 % mod;
    return (static_cast<ll>(a6) * to % mod +
            3ll * a4 % mod * sumb2[to] % mod +
            3ll * a2 % mod * sumb4[to] % mod +
            sumb6[to]) % mod;
}

int simpleSum(int n, int k) {
    int a = (n - k + 1 + mod) % mod;
    int b = (a + 1) % mod;
    int c = (n + 2ll * k) % mod;
    return static_cast<ll>(a) * b % mod * c % mod * inv6 % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    int siz = iSqrt(n) + 1;
    vector<int> sumb2(siz), sumb4(siz), sumb6(siz);
    for (int i = 1; i < siz; i++) {
        int b2 = static_cast<ll>(i) * i % mod;
        sumb2[i] = (sumb2[i - 1] + b2) % mod;
        int b4 = static_cast<ll>(b2) * b2 % mod;
        sumb4[i] = (sumb4[i - 1] + b4) % mod;
        int b6 = static_cast<ll>(b4) * b2 % mod;
        sumb6[i] = (sumb6[i - 1] + b6) % mod;
    }
    int sn = n % mod;
    int sn2 = static_cast<ll>(sn) * sn % mod;
    int sn3 = static_cast<ll>(sn2) * sn % mod;
    int mult0 = (sn3 + 3ll * sn2 + 2ll * sn) % mod;
    int mult1 = (3ll * sn + 4) % mod;
    int mult2 = (3ll * sn + 6) % mod;
    mult2 = (mod - mult2) % mod;
    int mult3 = 2;
    int res = 0;
    for (ll a = 0; a * a <= n; a++) {
        int to = iSqrt(n - a * a);
        int a2 = a * a % mod;
        int cur = static_cast<ll>(mult0) * to % mod;
        cur = (cur + static_cast<ll>(mult1) * sumK(a2, to, sumb2)) % mod;
        cur = (cur + static_cast<ll>(mult2) * sumK2(a2, to, sumb2, sumb4)) % mod;
        cur = (cur + static_cast<ll>(mult3) * sumK3(a2, to, sumb2, sumb4, sumb6)) % mod;
        cur = static_cast<ll>(cur) * inv6 % mod;
        cur = 2 * cur % mod;
        cur = (cur + simpleSum(sn, a2)) % mod;
        if (a) cur = 2 * cur % mod;
        res = (res + cur) % mod;
    }
    cout << res << "\n";
    return 0;
}
