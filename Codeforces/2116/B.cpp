#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int mod = 998244353;
constexpr int Maxn = 1e5 + 10;

int pw2[Maxn];
int T;
int n;
int p[Maxn], inp[Maxn];
int q[Maxn], inq[Maxn];

int main() {
    pw2[0] = 1;
    for (int i = 1; i < Maxn; ++i)
        pw2[i] = (pw2[i - 1] * 2) % mod;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            inp[p[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &q[i]);
            inq[q[i]] = i;
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, max(p[i], q[i]));
            int oth = 0;
            if (inp[mx] <= i)
                oth = max(oth, q[i - inp[mx]]);
            if (inq[mx] <= i)
                oth = max(oth, p[i - inq[mx]]);
            printf("%d%c", (pw2[mx] + pw2[oth]) % mod, " \n"[i == n - 1]);
        }
    }
    return 0;
}