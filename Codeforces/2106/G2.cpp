#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int res[Maxn];

int Ask(int v)
{
    printf("? 1 1 %d\n", v);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void Toggle(int v)
{
    printf("? 2 %d\n", v);
    fflush(stdout);
}

void Print()
{
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %d", res[i]);
    printf("\n");
    fflush(stdout);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
        }
        int g1 = Ask(1);
        Toggle(1);
        int g2 = Ask(1);
        res[1] = g2 > g1? 1: -1;
        if (g2 % 2)
            for (int i = 2; i <= n; i++)
                res[i] = Ask(i) - res[1];
        else {
            if (g2 != 0) {
                Toggle(1);
                res[1] = -res[1];
            }
            for (int i = 2; i <= n; i++)
                res[i] = Ask(i);
        }
        Print();
    }
    return 0;
}
