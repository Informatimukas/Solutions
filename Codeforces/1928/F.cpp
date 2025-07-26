#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 300005;
constexpr int Maxm = 1048576;

struct Intervals {
    int lef, rig, cnt;
    ll lefVal, rigVal;
    ll flag;
    Intervals(ll val = 0ll) {
        lef = rig = cnt = 1;
        lefVal = rigVal = val;
        flag = 0;
    }
    Intervals operator+(const Intervals &oth) const {
        Intervals res;
        res.lef = lef < cnt || rigVal != oth.lefVal ? lef: cnt + oth.lef;
        res.rig = oth.rig < oth.cnt || rigVal != oth.lefVal ? rig: oth.cnt + rig;
        res.cnt = cnt + oth.cnt;
        res.lefVal = lefVal;
        res.rigVal = rigVal;
        res.flag = 0;
        return res;
    }
};

ll coef1[Maxn], coef2[Maxn];

struct Mults {
    ll mult1, mult2, mult3;
    Mults() {
        mult1 = mult2 = mult3 = 0;
    }
    Mults(ll m1, ll m2, ll m3): mult1(m1), mult2(m2), mult3(m3) {}
    bool Zero() { return mult1 == 0 && mult2 == 0 && mult3 == 0; }
    Mults operator+(const Mults& oth) const {
        return {mult1 + oth.mult1, mult2 + oth.mult2, mult3 + oth.mult3};
    }
};

struct Sums {
    Mults m;
    ll sum;
    Mults fl;
    Sums() {
        sum = 0;
    }
    void downOn(int a, int b, const Mults& flag) {
        sum += (coef1[b] - coef1[a - 1]) * flag.mult1 +
            (coef2[b] - coef2[a - 1]) * flag.mult2 + flag.mult3;
        fl = fl + flag;
    }
};
int n[2], q;
int inp[2][Maxn];
Intervals st[2][Maxm];
Sums tr[2][Maxm];

void Create(int t, int v, int l, int r) {
    if (l == r)
        st[t][v] = Intervals(inp[t][l]);
    else {
        int m = l + r >> 1;
        Create(t, 2 * v, l, m);
        Create(t, 2 * v + 1, m + 1, r);
        st[t][v] = st[t][2 * v] + st[t][2 * v + 1];
    }
}

void addSums(int t, int v, int l, int r, int a, int b, const Mults& mults) {
    if (l == r)
}

int main() {
    for (int i = 1; i < Maxn; i++) {
        coef1[i] = coef1[i - 1] + i;
        coef2[i] = coef2[i - 1] + static_cast<ll>(i) * (i - 1) / 2;
    }
    scanf("%d %d %d", &n[0], &n[1], &q);
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= n[t]; i++)
            scanf("%d", &inp[t][i]);
        Create(t, 1, 1, n[t]);
    }
    return 0;
}