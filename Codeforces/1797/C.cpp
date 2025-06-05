#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int Ask(int r, int c)
{
    printf("? %d %d\n", r, c);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int a = Ask(1, 1);
        int b = Ask(n, 1);
        int X, Y;
        if (a + b == n - 1) {
            X = 1 + a;
            Y = 1 + Ask(X, 1);
        } else {
            Y = 1 + min(a, b);
            X = 1 + Ask(1, Y);
        }
        printf("! %d %d\n", X, Y);
        fflush(stdout);
    }
	return 0;
}
