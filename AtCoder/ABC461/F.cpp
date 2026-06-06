#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using ll = long long;
using hash_table = unordered_map<ll, int, custom_hash>;
using ii = pair<int, int>;

constexpr int mod = 998244353;
constexpr int Maxk = 13;

ii Join(const ii& a, const ii& b) {
    ii res;
    res.first = static_cast<ll>(a.first) * b.first % mod;
    res.second = (static_cast<ll>(a.first) * b.second + static_cast<ll>(b.first) * a.second) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    hash_table T;
    vector<ll> seq;
    for (ll i = 1; i * i <= n; i++)
        if (n % i == 0) {
            seq.push_back(i);
            if (n / i != i)
                seq.push_back(n / i);
        }
    ranges::sort(seq);
    for (int i = 0; i < seq.size(); i++)
        T.emplace(seq[i], i);
    vector trans(seq.size(), vector(seq.size(), -1));
    for (int i = 0; i < seq.size(); i++)
        for (int j = 0; j < seq.size(); j++)
            if (seq[i] % seq[j] == 0)
                trans[i][j] = T[seq[i] / seq[j]];
    vector dp(Maxk, vector(seq.size(), vector(seq.size(),  ii(0, 0))));
    for (int j = 0; j < seq.size(); j++)
        for (int k = j; k < seq.size(); k++)
            dp[0][j][k] = {1, seq[j] % mod};
    for (int i = 1; i < Maxk; i++)
        for (int j = 0; j < seq.size(); j++)
            for (int k = 1; k < seq.size(); k++) {
                dp[i][j][k] = dp[i][j][k - 1];
                if (trans[j][k] != -1) {
                    auto p = Join(dp[i - 1][trans[j][k]][k - 1], {1, seq[k] % mod});
                    dp[i][j][k].first = (dp[i][j][k].first + p.first) % mod;
                    dp[i][j][k].second = (dp[i][j][k].second + p.second) % mod;
                }
            }
    int res = 0;
    int fac = 1;
    for (int i = 0; i < Maxk; i++) {
        fac = static_cast<ll>(fac) * (i + 1) % mod;
        res = (res + static_cast<ll>(fac) * dp[i][seq.size() - 1][seq.size() - 1].second) % mod;
    }
    cout << res << "\n";
    return 0;
}
