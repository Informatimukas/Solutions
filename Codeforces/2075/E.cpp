#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1 << 29;
const int Maxb = 30;
const int mod = 998244353;

struct pos {
    int A, B;
    int b;
    bool operator<(const pos &oth) const {
        if (A != oth.A)
            return A < oth.A;
        if (B != oth.B)
            return B < oth.B;
        return b < oth.b;
    }
};

map <pos, int> M;

int Get(int A, int B, int b)
{
    if (b < 0) return 0;
    if (A > B) swap(A, B);
    pos p = {A, B, b};
    auto it = M.find(p);
    if (it != M.end())
        return it->second;
    int leaveA = min(A, (1 << b) - 1);
    int goA = A - (1 << b);
    int leaveB = min(B, (1 << b) - 1);
    int goB = B - (1 << b);
    int res = Get(leaveA, leaveB, b - 1);
    if (B & 1 << b)
        res = (res + Get(leaveA, goB, b - 1)) % mod;
    if (bool(A & 1 << b) && bool(B & 1 << b)) {
        res = (res + ll(goA + 1) * (goB + 1) % mod * (1 << b)) % mod;
        res = (res + Get(goA, goB, b - 1)) % mod;
    }
    if (A & 1 << b)
        res = (res + Get(goA, leaveB, b - 1)) % mod;
    M.insert({p, res});
    return res;
}

int T;
int n, m, A, B;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Mix(int n) { return (toPower(2, n) - 2 + mod) % mod; }

int C(int n, int k)
{
    if (n < 0 || k < 0 || k > n)
        return 0;
    if (k == 1) return n;
    if (k == 2) return ll(n) * (n - 1) / 2 % mod;
    assert(false);
    return -1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int n, m, A, B;
        scanf("%d %d %d %d", &n, &m, &A, &B);
        int res = ll(C(A + 1, 1)) * C(B + 1, 1) % mod;
        res = (res + ll(C(A + 1, 1)) * C(B + 1, 2) % mod * Mix(m)) % mod;
        res = (res + ll(C(A + 1, 2)) * C(B + 1, 1) % mod * Mix(n)) % mod;
        res = (res + ll(Get(A, B, Maxb - 1)) * Mix(n) % mod * Mix(m)) % mod;
        printf("%d\n", res);
    }
    return 0;
}
