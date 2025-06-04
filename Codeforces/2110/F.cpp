#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000006;

int T;
int n;
int a[Maxn];
set <int> S;
int un[Maxn], ulen;

int Solve()
{
    ulen = 0;
    auto it = S.rbegin();
    un[ulen++] = *it;
    it++;
    int res = 0;
    while (it != S.rend() && 2 * (*it) <= un[ulen - 1])
        un[ulen++] = *it;
    res = it == S.rend()? 0: un[ulen - 1];
    for (int i = 0; i < ulen; i++) if (2 * un[i] - 1 > res)
        for (int j = 0; j < i; j++)
            res = max(res, un[j] % un[i] + un[i]);
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
            S.insert(a[i]);
            printf("%d%c", Solve(), i + 1 <= n? ' ': '\n');
        }
    }
	return 0;
}
