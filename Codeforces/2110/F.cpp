#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000006;
const int Maxm = 2097152;
const int Inf = 1000000007;

int T;
int n;
int a[Maxn];
int un[Maxn], ulen;
bool tk[Maxn];
int mn[Maxm], lst[Maxm];

void Clear(int v, int l, int r)
{
    mn[v] = Inf;
    lst[v] = 0;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

int getSmaller(int v, int l, int r, int x)
{
    int res = mn[v];
    if (l == r) lst[v] = max(lst[v], un[x]);
    else {
        int m = l + r >> 1;
        if (x <= m) res = min(res, getSmaller(2 * v, l, m, x));
        else res = min(res, getSmaller(2 * v + 1, m + 1, r, x));
        return res;
    }
    return res;
}

int getBigger(int v, int l, int r, int a, int b, int x)
{
    if (l == a && r == b && un[a] / x == un[b] / x) {
        int cand = un[a] / x * x - x;
        mn[v] = min(mn[v], cand);
        return lst[v] > x? lst[v] - cand: 0;
    } else {
        int res = 0;
        int m = l + r >> 1;
        if (a <= m)
            res = max(res, getBigger(2 * v, l, m, a, m, x));
        if (m + 1 <= b)
            res = max(res, getBigger(2 * v + 1, m + 1, r, m + 1, b, x));
        return res;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ulen = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            un[ulen++] = a[i];
        }
        sort(un, un + ulen);
        ulen = unique(un, un + ulen) - un;
        fill(tk, tk + ulen, false);
        Clear(1, 0, ulen - 1);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int ind = lower_bound(un, un + ulen, a[i]) - un;
            if (!tk[ind]) {
                tk[ind] = true;
                printf("small = %d, big = %d\n", a[i] - getSmaller(1, 0, ulen - 1, ind), getBigger(1, 0, ulen - 1, ind, ulen - 1, a[i]));
                res = max(res, a[i] - getSmaller(1, 0, ulen - 1, ind));
                res = max(res, getBigger(1, 0, ulen - 1, ind, ulen - 1, a[i]));
            }
            printf("%d%c", res, i + 1 <= n? ' ': '\n');
        }
    }
	return 0;
}
