#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxk = 505;

int T;
int n, k;
ll p[Maxk];
int d[Maxk];
int q;
bool L[Maxk], R[Maxk];

bool Solve(ll x) {
    int ind = lower_bound(p, p + n, x) - p;
    fill_n(L, n, false);
    fill_n(R, n, false);
    ll tim = 0;
    bool right = true;
    while (true)
        if (right)
            if (ind == n) return true;
            else if ((tim + p[ind] - x) % k == d[ind])
                if (L[ind]) return false;
                else {
                    L[ind] = true;
                    x = p[ind];
                    tim = d[ind];
                    right ^= true;
                    ind--;
                } else ind++;
        else if (ind < 0) return true;
             else if ((tim + x - p[ind]) % k == d[ind])
                if (R[ind]) return false;
                else {
                    R[ind] = true;
                    x = p[ind];
                    tim = d[ind];
                    right ^= true;
                    ind++;
                } else ind--;
    assert(false);
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", &p[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &d[i]);
        scanf("%d", &q);
        while (q--) {
            ll ind;
            scanf("%lld", &ind);
            printf("%s\n", Solve(ind) ? "YES" : "NO");
        }
    }
    return 0;
}
