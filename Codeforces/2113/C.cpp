#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 505;

int T;
int n, m, k;
char B[Maxn][Maxn];
int G[Maxn][Maxn];

int Get(int r, int c) {
    r = min(r, n);
    c = min(c, m);
    if (r < 1 || c < 1) return 0;
    return G[r][c];
}

int Get(int r1, int c1, int r2, int c2) {
    printf("Get(%d, %d, %d, %d)\n", r1, c1, r2, c2);
    return Get(r2, c2) - Get(r1 - 1, c2) - Get(r2, c1 - 1) + Get(r1 - 1, c1 - 1);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%s", B[i] + 1);
            for (int j = 1; j <= m; j++) {
                G[i][j] = static_cast<int>(B[i][j] == 'g') + G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
                printf("G[%d][%d] = %d\n", i, j, G[i][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) if (B[i][j] == '.')
                res = max(res, Get(i - k, j - k, i + k, j + k) -
                    Get(i - k + 1, j - k + 1, i + k - 1, j + k - 1));
        printf("%d\n", res);
    }
    return 0;
}