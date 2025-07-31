#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 205;
constexpr int mod = 998244353;

void quickAdd(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector C(Maxn, vector(Maxn, 0));
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int sum = 0;
        for (auto& el : A) {
            cin >> el;
            sum += el;
        }
        if (sum > n - 1) {
            cout << "0\n";
            continue;
        }
        vector dp(n + 1, vector(n + 1, vector(n + 1, vector(n + 1, 0))));
        vector lef(n + 1, vector(n + 1, vector(n + 1, 0)));
        vector rig(n + 1, vector(n + 1, vector(n + 1, 0)));
        vector all(n + 1, vector(n + 1, 0));
        for (int s = 1; s <= n; s++)
            for (int i = 0, j = i + s - 1; j < n; i++, j++) {
                int lim = s - accumulate(A.begin() + i, A.begin() + j + 1, 0, [](int u, int v) {
                    return u + max(0, v);
                });
                for (int a = 0; a <= lim; a++)
                    for (int b = 0; a + b <= lim; b++)
                        for (int k = i; k <= j; k++) {
                            int s1 = k - i;
                            int s2 = j - k;
                            int na = a;
                            int nb = b;
                            if (i != 0 && (s1 <= s2 || j == n - 1)) {
                                if (na == 0) break;
                                na--;
                            } else {
                                if (nb == 0) break;
                                nb--;
                            }
                            int ways = 0;
                            if (A[k] == -1) {
                                int ways1 = s1? lef[i][k - 1][na]: static_cast<int>(na == 0);
                                int ways2 = s2? rig[k + 1][j][nb]: static_cast<int>(nb == 0);
                                ways = (ways + static_cast<ll>(ways1) * ways2) % mod;
                            } else {
                                for (int l = 0, r = A[k]; l <= A[k]; l++, r--)
                                    if (l <= s1 && r <= s2) {
                                        int ways1 = s1? dp[i][k - 1][na][l]: static_cast<int>(na == 0);
                                        int ways2 = s2? dp[k + 1][j][r][nb]: static_cast<int>(nb == 0);
                                        ways = (ways + static_cast<ll>(ways1) * ways2) % mod;
                                    }
                            }
                            ways = static_cast<ll>(ways) * C[s1 + s2][s1] % mod;
                            quickAdd(dp[i][j][a][b], ways);
                            quickAdd(lef[i][j][a], ways);
                            quickAdd(rig[i][j][b], ways);
                            quickAdd(all[i][j], ways);
                        }
            }
        cout << all[0][n - 1] << "\n";
    }
    return 0;
}
