#include <bits/stdc++.h>
using namespace std;

const int Maxk = 55;

int T;
int n, k;
int ina[Maxk], inb[Maxk];

void Write(int a, int b)
{
    if (a == -1)
        printf("! -1\n");
    else printf("! %d %d\n", a, b);
    fflush(stdout);
}

int Ask(int x)
{
    printf("? %d\n", x + 1);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (n == 2 * k) {
            Write(k, k);
            continue;
        }
        for (int i = 0; i < k; i++)
            ina[Ask(i)] = i;
        for (int i = n - k; i < n; i++)
            inb[Ask(i)] = i % k;
        int pnt = 1;
        while (pnt <= k && ina[pnt] == inb[pnt])
            pnt++;
        if (pnt > k) {
            Write(-1, -1);
            continue;
        }
        int lef = 1, rig = (n - 1 - ina[pnt]) / k;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Ask(mid * k + ina[pnt]) == pnt)
                lef = mid + 1;
            else rig = mid - 1;
        }
        int L = rig * k + ina[pnt];
        int R = lef * k + ina[pnt];
        while (L % k == ina[Ask(L)])
            L++;
        L--;
        while (R % k == inb[Ask(R)])
            R--;
        R++;
        if (L + 1 == R)
            Write(L + 1, n - (L + 1));
        else Write(-1, -1);
    }
    return 0;
}
