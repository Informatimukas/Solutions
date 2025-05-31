#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n, q;
int b[Maxn];
bool fre[Maxn];
int mn[Maxn];
int res[Maxn];
int X[Maxn], Y[Maxn], Z[Maxn];

bool Check()
{
    for (int i = q - 1; i >= 0; i--) {
        int val = fre[Z[i]]? mn[Z[i]]: b[Z[i]];
        fre[Z[i]] = true;
        mn[Z[i]] = 0;
        if (fre[X[i]]) mn[X[i]] = max(mn[X[i]], val);
        if (fre[Y[i]]) mn[Y[i]] = max(mn[Y[i]], val);
    }
    for (int i = 1; i <= n; i++) {
        mn[i] = fre[i]? mn[i]: b[i];
        res[i] = mn[i];
    }
    for (int i = 0; i < q; i++)
        mn[Z[i]] = min(mn[X[i]], mn[Y[i]]);
    for (int i = 1; i <= n; i++)
        if (mn[i] != b[i])
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            fre[i] = false;
        }
        for (int i = 0; i < q; i++)
            scanf("%d %d %d", &X[i], &Y[i], &Z[i]);
        if (Check())
            for (int i = 1; i <= n; i++)
                printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
        else printf("-1\n");
    }
	return 0;
}
