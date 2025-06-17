#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int r = (n + 1) / 2, c = (m + 1) / 2;
        printf("%d %d\n", r, c);
        int mnr = r, mxr = r, mnc = c, mxc = c;
        bool rows = true;
        while (mnr > 1 || mxr < n || mnc > 1 || mxc < m) {
            if (rows && mnr > 1) {
                int md = (mnc + mxc) / 2;
                mnr--;
                mxr++;
                printf("%d %d\n", mnr, md);
                printf("%d %d\n", mxr, md);
                for (int i = 1; i <= mxc - md; i++) {
                    printf("%d %d\n", mnr, md - i);
                    printf("%d %d\n", mxr, md + i);
                    printf("%d %d\n", mnr, md + i);
                    printf("%d %d\n", mxr, md - i);
                }
            } else if (!rows && mnc > 1) {
                int md = (mnr + mxr) / 2;
                mnc--;
                mxc++;
                printf("%d %d\n", md, mnc);
                printf("%d %d\n", md, mxc);
                for (int i = 1; i <= mxr - md; i++) {
                    printf("%d %d\n", md - i, mnc);
                    printf("%d %d\n", md + i, mxc);
                    printf("%d %d\n", md + i, mnc);
                    printf("%d %d\n", md - i, mxc);
                }
            }
            rows = !rows;
        }
    }
    return 0;
}