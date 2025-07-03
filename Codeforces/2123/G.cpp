#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 500005;

int T;
int n, m, q;
int inp[Maxn];
int a[Maxn];
int qa[Maxn], qb[Maxn], qc[Maxn];
bool res[Maxn];
vector<int> un;

int Gcd(int x, int y) { return y == 0 ? x : Gcd(y, x % y); }

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &inp[i]);
        un.clear();
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &qa[i], &qb[i]);
            if (qa[i] == 1) scanf("%d", &qc[i]);
            else {
                qb[i] = Gcd(qb[i], m);
                un.push_back(qb[i]);
            }
        }
        ranges::sort(un);
        un.erase(ranges::unique(un).begin(), un.end());
        for (int z = 0; z < un.size(); z++) {
            int g = un[z];
            ll sum = 0;
            for (int i = 1; i <= n; i++) {
                a[i] = inp[i] % g;
                if (i && a[i - 1] > a[i])
                    sum += g;
            }
            for (int i = 1; i <= q; i++)
                if (qa[i] == 1) {
                    int ind = qb[i];
                    if (ind && a[ind - 1] > a[ind])
                        sum -= g;
                    if (ind < n && a[ind] > a[ind + 1])
                        sum -= g;
                    a[ind] = qc[i] % g;
                    if (ind && a[ind - 1] > a[ind])
                        sum += g;
                    if (ind < n && a[ind] > a[ind + 1])
                        sum += g;
                } else if (qb[i] == g)
                    res[i] = sum + a[n] < m;
        }
        for (int i = 1; i <= q; i++)
            if (qa[i] == 2)
                printf("%s\n", res[i]? "YES": "NO");
    }
    return 0;
}
