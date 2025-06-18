#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxk = 400005;

int T;
int n, k;
ll p[Maxk];
ll d[Maxk];
int nxt[Maxk];
bool tk[Maxk], cyc[Maxk];
int q;
bool L[Maxk], R[Maxk];

bool getCycle(int x) {
    if (tk[x] == 2) return false;
    if (tk[x] == 1) return true;
    tk[x] = 1;
    cyc[x] = nxt[x] != -1 && getCycle(nxt[x]);
    tk[x] = 2;
    return cyc[x];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", &p[i]);
        for (int i = 0; i < n; i++)
            scanf("%lld", &d[i]);
        fill_n(tk, n, 0);
        fill_n(nxt, n, -1);
        scanf("%d", &q);
        while (q--) {
            ll ind;
            scanf("%lld", &ind);
            printf("%s\n", Solve(ind) ? "YES" : "NO");
        }
    }
    return 0;
}
