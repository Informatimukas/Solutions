#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxf = 11;

int T;
int n, m;
ll f[Maxf];

int main() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < Maxf; i++)
        f[i] = f[i - 1] + f[i - 2];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int w, l, h;
            scanf("%d %d %d", &w, &l, &h);
            if (w >= f[n] && l >= f[n] && h >= f[n] &&
                (w >= f[n] + f[n - 1] || l >= f[n] + f[n - 1] || h >= f[n] + f[n - 1]))
                printf("1");
            else printf("0");
        }
        printf("\n");
    }
    return 0;
}