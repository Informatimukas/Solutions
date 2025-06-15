#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000006;

int T;
int n;
int a[Maxn];
set <int> S;

int Solve(int a, int res)
{
    if (2 * a - 1 <= res) return res;
    for (auto it = S.rbegin(); it != S.rend() && 2 * min(*it, a) - 1 > res; ++it) {
        res = max(res, *it % a + a % *it);
        if (max(*it, a) <= res) break;
    }
    S.insert(a);
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        S.clear();
        int res = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (!S.count(a[i]))
                res = Solve(a[i], res);
            printf("%d%c", res, i + 1 <= n? ' ': '\n');
        }
    }
	return 0;
}
