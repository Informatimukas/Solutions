#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;
constexpr int Maxm = 500005;

struct pos {
    vector<int> seq;
    int nd{0};
};

ll solvePos(const vector<int>& seq, int nd) {
    if (seq.empty())
        return nd == 0 ? 1 : 0;
    int lim = *ranges::max_element(seq);
    ll res = 0;
    for (int mx = 0; mx <= lim; mx++) {
        vector dp(2, vector<ll>(nd + 2));
        dp[0][nd] = 1;
        for (auto has : seq) {
            vector ndp(2, vector<ll>(nd + 2));
            for (int j = 0; j < 2; j++) {
                ll ways = 0;
                for (int k = 0; k <= nd; k++) {
                    ways = (ways + dp[j][k]) % mod;
                    // take max
                    if (mx <= has)
                        if (j == 0) {
                            ndp[1][k] = (ndp[1][k] + ways) % mod;
                            ndp[1][k + 1] = (ndp[1][k + 1] - ways + mod) % mod;
                        } else if (k >= mx) {
                            ndp[1][k - mx] = (ndp[1][k - mx] + ways) % mod;
                            ndp[1][k - mx + 1] = (ndp[1][k - mx + 1] - ways + mod) % mod;
                        }
                    if (int tk = min({mx - 1, has, k}); tk >= 0) {
                        ndp[j][k - tk] = (ndp[j][k - tk] + ways) % mod;
                        ndp[j][k + 1] = (ndp[j][k + 1] - ways + mod) % mod;
                    }
                }
            }
            dp = ndp;
        }
        res = (res + dp[1][0]) % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx(Maxm);
    for (int i = 2; i < Maxm; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxm; j += i)
                mx[j] = i;
    int T;
    cin >> T;
    while (T--) {
        map<int, pos> M;
        int n, x;
        cin >> n >> x;
        while (x > 1) {
            M[mx[x]].nd++;
            x /= mx[x];
        }
        while (n--) {
            int a;
            cin >> a;
            while (a > 1) {
                int cur = mx[a], cnt = 0;
                while (mx[a] == cur) {
                    a /= cur;
                    cnt++;
                }
                M[cur].seq.push_back(cnt);
            }
        }
        ll res = 1;
        for (auto& p : M | views::values)
            res = res * solvePos(p.seq, p.nd) % mod;
        cout << res << "\n";
    }
    return 0;
}
