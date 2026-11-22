#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

constexpr int Maxn = 2005;
constexpr ll mod = 998244353;
constexpr int Maxm = 11;

vector<ll> fac(Maxn);
vector C(Maxn, vector<ll>(Maxn));

ii Process(int x) {
    int cnt = 0;
    int res = 0;
    while (x) {
        if (cnt == 0)
            res = (res + x % 10) % Maxm;
        else res = (res - x % 10 + Maxm) % Maxm;
        cnt = 1 - cnt;
        x /= 10;
    }
    return {cnt, res};
}

vector<vector<ll>> Solve(const vector<int>& seq) {
    vector dp(seq.size() + 1, vector(Maxm, 0ll));
    dp[0][0] = 1;
    for (int i = 0; i < seq.size(); i++) {
        vector ndp(seq.size() + 1, vector(Maxm, 0ll));
        for (int j = 0; j <= i; j++)
            for (int k = 0; k < Maxm; k++) {
                int nk = (k + seq[i]) % Maxm;
                ndp[j + 1][nk] = (ndp[j + 1][nk] + dp[j][k]) % mod;
                nk = (k - seq[i] + Maxm) % Maxm;
                ndp[j][nk] = (ndp[j][nk] + dp[j][k]) % mod;
            }
        dp = ndp;
    }
    return dp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < Maxn; i++)
        fac[i] = i * fac[i - 1] % mod;
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    int T;
    cin >> T;
    while (T--) {
        array<vector<int>, 2> seq;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            auto got = Process(a);
            seq[got.first].push_back(got.second);
        }
        array dp = {Solve(seq[0]), Solve(seq[1])};
        ll res = 0;
        int nd = (seq[1].size() + 1) / 2;
        if (nd == 0)
            res = dp[0][n][0] * fac[n] % mod;
        else {
            for (int i = 0; i <= seq[0].size(); i++)
                for (int j = 0; j < Maxm; j++) {
                    int oth = (Maxm - j) % Maxm;
                    res = (res + dp[0][i][j] * dp[1][nd][oth] % mod * fac[i] % mod * fac[seq[0].size() - i] % mod *
                        fac[nd] % mod * fac[seq[1].size() - nd] % mod * C[i + seq[1].size() / 2][i] % mod *
                        C[seq[0].size() - i + nd - 1][nd - 1]) % mod;
                }
        }
        cout << res << "\n";
    }
    return 0;
}
