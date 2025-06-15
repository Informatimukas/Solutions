#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 101;
constexpr int Maxm = 20105;
constexpr int mod = 1000000007;

int C[Maxn][Maxn];
int fac[Maxn];
int mn[Maxn], mx[Maxn];
int dp[Maxn][Maxm];

int main()
{
    fac[0] = 1;
    C[0][0] = 1;
    for (int i = 1; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        fac[i] = ll(fac[i - 1]) * i % mod;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    mn[0] = mx[0] = 0;
    dp[0][0] = 1;
    for (int i = 1; i < Maxn; i++) {
        int a = (i - 1) / 2;
        int b = i - 1 - a;
        mn[i] = i + mn[a] + mn[b];
        mx[i] = i + mx[0] + mx[i - 1];
        for (int c = 0; c <= a; c++) {
            int d = i - 1 - c;
            int mult = c == d? 1: 2;
            mult = ll(mult) * C[i - 1][c] % mod;
            for (int k1 = mn[c]; k1 <= mx[c]; k1++)
                for (int k2 = mn[d]; k2 <= mx[d]; k2++)
                    dp[i][k1 + k2 + i] = (dp[i][k1 + k2 + i] +
                        ll(dp[c][k1]) * dp[d][k2] % mod * mult) % mod;
        }
    }
    for (int i = 1; i <= 10; i++)
        for (int j = mn[i]; j <= mx[i]; j++)
            printf("%d%c", dp[i][j], j == mx[i]? '\n': ' ');
    return 0;
}
