#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, q;
int a[Maxn];

int Sum(int x)
{
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        set <int> S;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] >= 10)
                S.insert(i);
        }
        while (q--) {
            int typ;
            scanf("%d", &typ);
            if (typ == 1) {
                int l, r; scanf("%d %d", &l, &r);
                auto it = S.lower_bound(l);
                while (it != S.end() && *it <= r) {
                    a[*it] = Sum(a[*it]);
                    if (a[*it] >= 10) it++;
                    else S.erase(it++);
                }
            } else {
                int x; scanf("%d", &x);
                printf("%d\n", a[x]);
            }
        }
    }
    return 0;
}
