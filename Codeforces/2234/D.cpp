#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxk = 31;
constexpr int Maxd = 4;

ll Get(const string& s) {
    array<ll, 2> cnt{};
    for (auto ch : s)
        cnt[ch - '0']++;
    return cnt[0] * cnt[1];
}

ll Get(const string& a, const string& b) {
    array<ll, 2> cnt{};
    for (int i = 0; i < a.length(); i++) {
        auto ch1 = a[i] - '0', ch2 = b[i] - '0';
        cnt[ch1 ^ ch2]++;
    }
    return cnt[0] * cnt[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector dp(Maxk, vector(Maxd, vector(Maxd, array<int, Maxd>{})));
    for (int i = 1; i < Maxk; i++)
        for (int j = 0; j < Maxd; j++)
            for (int k = 0; k < Maxd; k++) {
                int m = j ^ k;
                dp[i][j][k][m]++;
                for (int z = 0; z < Maxd; z++)
                    dp[i][j][k][z] += dp[i - 1][j][m][z] + dp[i - 1][m][k][z];
            }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        auto res = dp[k][1][2];
        res[1]++;
        res[2]++;
        ll ans = res[1] * Get(a) + res[2] * Get(b) + res[3] * Get(a, b);
        cout << ans << "\n";
    }
    return 0;
}
