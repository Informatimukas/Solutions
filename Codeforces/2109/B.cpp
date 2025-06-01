#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, a, b;

int Solve(int n, int x)
{
    int res = 0;
    while (n > 1) {
        res++;
        n = min(x, n - x + 1);
        x = (n + 1) / 2;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        printf("%d\n", min(Solve(n, a) + Solve(m, (m + 1) / 2),
                           Solve(m, b) + Solve(n, (n + 1) / 2)));
    }
	return 0;
}
