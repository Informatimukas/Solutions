#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 1000005;
constexpr int Maxk = 26;

int n, k;
char str[Maxn];
int nxt[Maxn][Maxk];
int dp[Maxn];
int q;
char oth[Maxn];

int main() {
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    dp[n + 1] = 0;
    dp[n] = 1;
    fill_n(nxt[n], k, n);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = Maxn;
        for (int j = 0; j < k; j++) {
            nxt[i][j] = nxt[i + 1][j];
            if (str[i] == 'a' + j)
                nxt[i][j] = i;
            if (nxt[i][j] >= n)
                dp[i] = 1;
            else dp[i] = min(dp[i], dp[nxt[i][j] + 1] + 1);
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%s", oth);
        int pnt = 0, len = strlen(oth);
        for (int i = 0; i < len && pnt <= n; i++)
            pnt = nxt[pnt][oth[i] - 'a'] + 1;
        printf("%d\n", dp[pnt]);
    }
    return 0;
}