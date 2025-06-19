#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;

constexpr int Maxk = 400005;

int T;
int n;
ll k;
ll p[Maxk];
ll d[Maxk];
int nxt[Maxk];
int tk[Maxk];
bool cyc[Maxk];
int q;
lli quer[Maxk];
bool res[Maxk];

bool getCycle(int x) {
    if (tk[x] == 2) return cyc[x];
    if (tk[x] == 1) return true;
    tk[x] = 1;
    cyc[x] = nxt[x] != -1 && getCycle(nxt[x]);
    tk[x] = 2;
    return cyc[x];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", &p[i]);
        for (int i = 0; i < n; i++)
            scanf("%lld", &d[i]);
        fill_n(tk, 2 * n, 0);
        fill_n(nxt, 2 * n, -1);
        map<ll, int> M;
        for (int i = 0; i < n; i++) {
            ll val = (p[i] + d[i]) % k;
            auto it = M.find(val);
            if (it != M.end())
                nxt[i] = n + it->second;
            M[val] = i;
        }
        M.clear();
        for (int i = n - 1; i >= 0; i--) {
            ll val = (p[i] - d[i] + k) % k;
            auto it = M.find(val);
            if (it != M.end())
                nxt[n + i] = it->second;
            M[val] = i;
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%lld", &quer[i].first);
            quer[i].second = i;
        }
        sort(quer, quer + q);
        int pnt = n - 1;
        M.clear();
        for (int i = q - 1; i >= 0; i--) {
            while (pnt >= 0 && quer[i].first <= p[pnt]) {
                ll val = (p[pnt] - d[pnt] + k) % k;
                if (getCycle(pnt))
                    M[val] = 1;
                else M[val] = 0;
                pnt--;
            }
            res[quer[i].second] = !M[quer[i].first % k];
        }
        for (int i = 0; i < q; i++)
            printf("%s\n", res[i]? "YES" : "NO");
    }
    return 0;
}
