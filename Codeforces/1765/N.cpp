#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Maxd = 10;

int T;
char str[Maxn];
int slen;
int k;
int nxt[Maxn][Maxd];
char res[Maxn];
int rlen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        scanf("%d", &k);
        fill(nxt[slen], nxt[slen] + Maxd, slen);
        for (int i = slen - 1; i >= 0; i--) {
            for (int j = 0; j < Maxd; j++)
                nxt[i][j] = nxt[i + 1][j];
            nxt[i][str[i] - '0'] = i;
        }
        int from = 1, pnt = 0;
        rlen = 0;
        int nd = slen - k;
        while (rlen < nd) {
            int cur = from;
            while (nxt[pnt][cur] - pnt > k)
                cur++;
            k -= (nxt[pnt][cur] - pnt);
            res[rlen++] = cur + '0';
            pnt = nxt[pnt][cur] + 1;
            from = 0;
        }
        res[rlen] = '\0';
        printf("%s\n", res);
    }
	return 0;
}
