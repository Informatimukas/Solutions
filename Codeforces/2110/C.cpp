#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int d[Maxn];
int L[Maxn], R[Maxn];
int lef[Maxn], rig[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &d[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &L[i], &R[i]);
        L[0] = R[0] = 0;
        lef[n] = L[n];
        rig[n] = R[n];
        bool bad = false;
        for (int i = n; i >= 1; i--) {
            lef[i - 1] = Maxn;
            rig[i - 1] = -Maxn;
            if (d[i] == 0 || d[i] == -1) {
                lef[i - 1] = min(lef[i - 1], lef[i]);
                rig[i - 1] = max(rig[i - 1], rig[i]);
            }
            if (d[i] == 1 || d[i] == -1) {
                lef[i - 1] = min(lef[i - 1], lef[i] - 1);
                rig[i - 1] = max(rig[i - 1], rig[i] - 1);
            }
            lef[i - 1] = max(lef[i - 1], L[i - 1]);
            rig[i - 1] = min(rig[i - 1], R[i - 1]);
            if (lef[i - 1] > rig[i - 1]) {
                bad = true;
                break;
            }
        }
        if (bad) {
            printf("-1\n");
            continue;
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] == -1)
                if (lef[i] <= cur && cur <= rig[i])
                    d[i] = 0;
                else d[i] = 1;
            cur += d[i];
            printf("%d%c", d[i], i + 1 <= n? ' ': '\n');
        }
    }
	return 0;
}
