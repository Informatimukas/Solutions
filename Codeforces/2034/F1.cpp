#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int mod = 998244353;

struct pos {
    int value, prob;
    pos(int value = 0, int prob = 0): value(value), prob(prob) {}
    pos operator+(const pos& oth) const {
        return {(value + oth.value) % mod, (prob + oth.prob) % mod};
    }
    pos operator*(const pos& oth) const {
        int nvalue = (static_cast<ll>(value) * oth.prob +
            static_cast<ll>(prob) * oth.value) % mod;
        int nprob = static_cast<ll>(prob) * oth.prob % mod;
        return {nvalue, nprob};
    }
};

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
    return static_cast<ll>(fac[n]) * ifac[n - k] % mod * ifac[k] % mod;
}

pos getPos(const ii& a, const ii& b, int from, const vector<int>& fac, const vector<int>& ifac) {
    int rdif = a.first - b.first;
    int bdif = a.second - b.second;
    if (rdif < 0 || bdif < 0)
        return {0, 0};
    int tkr = C(a.first, rdif, fac, ifac);
    int tkb = C(a.second, bdif, fac, ifac);
    int tkboth = C(a.first + a.second, rdif + bdif, fac, ifac);
    int prob = static_cast<ll>(tkr) * tkb % mod * Inv(tkboth) % mod;
    int value = from == 0 ? rdif * 2 + bdif : 0;
    value = static_cast<ll>(value) * prob % mod;
    return {value, prob};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> fac(n + m + 1), ifac(n + m + 1);
        fac[0] = ifac[0] = 1;
        for (int i = 1; i < fac.size(); i++) {
            fac[i] = static_cast<ll>(fac[i - 1]) * i % mod;
            ifac[i] = Inv(fac[i]);
        }
        vector<ii> rb(k);
        for (auto& [r, b] : rb)
            cin >> r >> b;
        rb.emplace_back(n, m);
        rb.emplace_back(0, 0);
        ranges::sort(rb, [](const ii& a, const ii& b) {
            return a.first + a.second > b.first + b.second;
        });
        vector<pos> res(rb.size());
        res[0] = {0, 1};
        for (int i = 0; i < res.size(); i++)
            for (int j = i + 1; j < res.size(); j++)
                res[j] = res[j] + res[i] * getPos(rb[i], rb[j], i, fac, ifac);
        cout << res.back().value << "\n";
    }
    return 0;
}