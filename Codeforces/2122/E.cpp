#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 505;
constexpr int Maxm = Maxn * Maxn;
constexpr int mod = 998244353;

int T;
int n, k;
int B[2][Maxn];
int bad[Maxn][Maxn], good[Maxn];
int curGood[Maxn], curBad[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &B[i][j]);
        for (int i = 0; i <= n; i++) {
            fill_n(bad[i], k + 1, 0);
            good[i] = 0;
        }
        int extr = B[0][0] == -1? k: 1;
        good[1] = extr;
        for (int i = 1; i < n; i++) {
            fill_n(curBad, k + 1, 0);
            fill_n(curGood, k + 1, 0);
            for (int j = 1; j <= k; j++) if (B[0][i] == -1 || B[0][i] == j)
                for (int l = 1; l <= k; l++) if (B[1][i - 1] == -1 || B[1][i - 1] == l)
                    if (j >= l) curGood[j - l]++;
                    else curBad[l - j]++;
            for (int l = 0; l <= k; l++) {
                for (int j = 0; j <= k; j++)
                    bad[i + 1][l] = (bad[i + 1][l] + static_cast<ll>(bad[i][j]) * curBad[l]) % mod;
                bad[i + 1][l] = (bad[i + 1][l] + static_cast<ll>(good[i]) * curBad[l]) % mod;
                good[i + 1] = (good[i + 1] + static_cast<ll>(good[i]) * curGood[l]) % mod;
                for (int j = l; j <= k; j++)
                    bad[i + 1][j - l] = (bad[i + 1][j - l] + static_cast<ll>(bad[i][j]) * curGood[l]) % mod;
            }
        }
        int res = good[n];
        for (int j = 0; j <= k; j++)
            res = (res + bad[n][j]) % mod;
        if (B[1][n - 1] == -1)
            res = static_cast<ll>(res) * k % mod;
        printf("%d\n", res);
    }
    return 0;
}