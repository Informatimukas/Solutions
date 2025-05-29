#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];
int L[Maxn], R[Maxn], sL[Maxn], sR[Maxn];

int Get(int x, int y)
{
    int tot = 1;
    while (x % 2 == 0 && x / 2 != y) {
        x /= 2;
        tot *= 2;
    }
    return tot;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            L[i] = L[i - 1];
            sL[i] = L[i - 1];
            int num = a[i];
            while (num % 2 == 0)
                num /= 2;
            if (i > 1) {
                sL[i] += max(Get(a[i - 1], a[i]), Get(a[i - 1], num));
                L[i] += Get(a[i - 1], a[i]);
            }
        }
        R[n + 1] = 0;
        int mx = 0;
        for (int i = n; i > 0; i--) {
            R[i] = R[i + 1];
            sR[i] = R[i + 1];
            int num = a[i];
            while (num % 2 == 0)
                num /= 2;
            if (i < n) {
                sR[i] += max(Get(a[i + 1], a[i]), Get(a[i + 1], num));
                R[i] += Get(a[i + 1], a[i]);
            }
            int got = Get(a[i], 0);
            mx = max(mx, got + max(sL[i] + R[i], L[i] + sR[i]));
        }
        printf("%s\n", mx >= k? "YES": "NO");
    }
	return 0;
}
