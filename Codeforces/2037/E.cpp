#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;
int res[Maxn];
char str[Maxn];

int Ask(int l, int r)
{
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
            res[i] = Ask(1, i);
        if (res[n] == 0) {
            printf("! IMPOSSIBLE\n");
            fflush(stdout);
            continue;
        }
        int pnt = 2;
        str[1] = '1';
        while (res[pnt] == 0) str[pnt++] = '1';
        for (int i = 1; i <= res[pnt]; i++)
            str[pnt - i] = '0';
        str[pnt++] = '1';
        while (pnt <= n)
            if (res[pnt] > res[pnt - 1])
                str[pnt++] = '1';
            else str[pnt++] = '0';
        str[pnt] = '\0';
        printf("! %s\n", str + 1);
        fflush(stdout);
    }
	return 0;
}
