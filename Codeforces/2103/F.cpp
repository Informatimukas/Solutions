#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxk = 17;
const int Maxm = 262144;

int T;
int n, k;
int a[Maxn];
int lst[Maxk];
int st[Maxm];

void Clear(int v, int l, int r)
{
    st[v] = 0;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

void Add(int v, int l, int r, int a, int b, int cand)
{
    if (l == a && r == b)
        st[v] = max(st[v], cand);
    else {
        int m = l + r >> 1;
        if (a <= m)
            Add(2 * v, l, m, a, min(m, b), cand);
        if (m + 1 <= b)
            Add(2 * v + 1, m + 1, r, max(m + 1, a), b, cand);
    }
}

int Get(int v, int l, int r, int x)
{
    int res = st[v];
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m)
            res = max(res, Get(2 * v, l, m, x));
        else res = max(res, Get(2 * v + 1, m + 1, r, x));
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        Clear(1, 1, n);
        fill(lst, lst + k, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            for (int j = 0; j < k; j++)
                if (a[i] & 1 << j)
                    lst[j] = i;
            int cand = 0;
            int lft = (1 << k) - 1;
            int pnt = i;
            while (pnt > 0) {
                int mx = 0;
                for (int j = 0; j < k; j++)
                    if (lft & 1 << j)
                        mx = max(mx, lst[j]);
                if ((i - mx) % 2 == 0) {
                    if (mx + 1 <= pnt)
                        Add(1, 1, n, mx + 1, i, cand | lft);
                    if (mx == 0) break;
                    for (int j = 0; j < k; j++)
                        if (bool(lft & 1 << j) && lst[j] == mx)
                            cand |= 1 << j;
                    Add(1, 1, n, mx, i, cand);
                    for (int j = 0; j < k; j++)
                        if (bool(lft & 1 << j) && lst[j] == mx) {
                            cand ^= 1 << j;
                            lft ^= 1 << j;
                        }
                    pnt = mx - 1;
                } else {
                    if (mx + 2 <= pnt)
                        Add(1, 1, n, mx + 2, i, cand | lft);
                    if (mx + 1 <= pnt)
                        Add(1, 1, n, mx + 1, i, cand);
                    if (mx == 0) break;
                    int ncand = cand | lft;
                    for (int j = 0; j < k; j++)
                        if (bool(lft & 1 << j) && lst[j] == mx)
                            ncand ^= 1 << j;
                    Add(1, 1, n, mx, i, ncand);
                    for (int j = 0; j < k; j++)
                        if (bool(lft & 1 << j) && lst[j] == mx) {
                            lft ^= 1 << j;
                            cand ^= 1 << j;
                        }
                    pnt = mx - 1;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d%c", Get(1, 1, n, i), i + 1 <= n? ' ': '\n');
    }
    return 0;
}
