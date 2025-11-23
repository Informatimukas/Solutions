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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<int> fac(s.length() + 1), ifac(s.length() + 1);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < fac.size(); i++) {
        fac[i] = static_cast<ll>(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    vector<int> L(s.length()), R(s.length());
    map<char, int> M;
    for (int i = 0; i < s.length(); i++) {
        L[i] = M[s[i] - 1];
        ++M[s[i]];
    }
    M.clear();
    int res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        R[i] = M[s[i]]++;
        res = (res + C(L[i] + R[i], L[i] - 1, fac, ifac)) % mod;
    }
    cout << res << "\n";
    return 0;
}