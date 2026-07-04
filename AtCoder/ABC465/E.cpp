#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 505;
constexpr int Maxd = 10;
constexpr int Maxk = 3;
constexpr int mod = 998244353;

bool Good(int mask, int mod3) {
    int satisfied = (mod3 == 0);
    satisfied += (mask & 1 << Maxk) > 0;
    satisfied += __builtin_popcount(mask) == Maxk;
    return satisfied == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector dp(Maxn, vector(1 << Maxd, vector(Maxk, 0)));
    vector dpall(Maxn, vector(1 << Maxd, vector(Maxk, 0)));
    dpall[0][0][0] = 1;
    for (int i = 1; i < Maxn; i++) {
        for (int d = 1; d < Maxd; d++)
            for (int j = 0; j < 1 << Maxd; j++)
                for (int k = 0; k < Maxk; k++) {
                    int nj = j | 1 << d;
                    int nk = (k + d) % Maxk;
                    dp[i][nj][nk] = (dp[i][nj][nk] + dpall[i - 1][j][k]) % mod;
                }
        for (int d = 0; d < Maxd; d++)
            for (int j = 0; j < 1 << Maxd; j++)
                for (int k = 0; k < Maxk; k++) {
                    int nj = j | 1 << d;
                    int nk = (k + d) % Maxk;
                    dpall[i][nj][nk] = (dpall[i][nj][nk] + dpall[i - 1][j][k]) % mod;
                }
    }
    string s;
    cin >> s;
    int res = 0;
    for (int i = 1; i < s.length(); i++)
        for (int j = 0; j < 1 << Maxd; j++)
            for (int k = 0; k < Maxk; k++)
                if (Good(j, k))
                    res = (res + dp[i][j][k]) % mod;
    int mask = 0, sum = 0;
    for (int i = 0; i < s.length(); i++) {
        int lft = s.length() - 1 - i;
        for (int j = i == 0 ? 1 : 0; j < s[i] - '0'; j++)
            for (int z = 0; z < 1 << Maxd; z++)
                for (int c = 0; c < Maxk; c++)
                    if (Good(mask | 1 << j | z, (sum + j + c) % Maxk))
                        res = (res + dpall[lft][z][c]) % mod;
        int d = s[i] - '0';
        mask |= 1 << d;
        sum = (sum + d) % Maxk;
    }
    if (Good(mask, sum))
        res = (res + 1) % mod;
    cout << res << "\n";
    return 0;
}
