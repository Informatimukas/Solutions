#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int T;
int n, m;
int N;
int A[Maxn];
int B[Maxn];
ii HA[Maxn], HB[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

ii addHash(ii h, int nw)
{
    h.first = (ll(h.first) * arg1 + nw) % mod1;
    h.second = (ll(h.second) * arg2 + nw) % mod2;
    return h;
}

ii getHash(ii H[], int l, int r)
{
    ii res = H[r];
    if (--l >= 0) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

int main()
{
    mod1 = uniform_int_distribution<int>(10000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(10000000, 1000000000)(rng);
    arg1 = uniform_int_distribution<int>(100000, 10000000)(rng);
    arg2 = uniform_int_distribution<int>(100000, 10000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        N = n * m;
        ii h = {0, 0};
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            h = addHash(h, A[i]);
            HA[i] = h;
        }
        int res = 0;
        int pnt = 0;
        deque <int> D;
        for (int i = 0; i < n; i++) {
            h = {0, 0};
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[j]);
                h = addHash(h, B[j]);
                HB[j] = h;
            }
            int add = 0;
            for (int j = 0; j < m; j++)
                if (!D.empty())
                    if (D.front() == B[j]) {
                        add++;
                        D.pop_front();
                    } else {
                        add++;
                        res++;
                    }
                else {
                    int cand = m - j;
                    if (getHash(HA, i * m, i * m + cand - 1) ==
                        getHash(HB, m - cand, m - 1))
                        break;
                    add++;
                    res++;
                }
            for (int j = (i + 1) * m - add; j < (i + 1) * m; j++)
                D.push_back(A[j]);
        }
        printf("%d\n", res);
    }
    return 0;
}