#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

constexpr int Maxn = 300005;
constexpr int Maxm = 1048576;

ll coef1[Maxn], coef2[Maxn];

struct Mults {
    ll mult1, mult2, mult3;
    Mults() {
        mult1 = mult2 = mult3 = 0;
    }
    Mults(ll m1, ll m2, ll m3): mult1(m1), mult2(m2), mult3(m3) {}
    bool Zero() { return mult1 == 0 && mult2 == 0 && mult3 == 0; }
    Mults& operator+=(const Mults& oth) {
        mult1 += oth.mult1;
        mult2 += oth.mult2;
        mult3 += oth.mult3;
        return *this;
    }
};

int n[2], q;
int inp[2][Maxn];
ll BIT[2][Maxm];
set<ii> S[2];
ll tr[2][Maxm];
Mults fl[2][Maxm];
ll res;

void addBIT(int t, int x, ll val) {
    for (int i = x; i <= n[t]; i += i & -i)
        BIT[t][i] += val;
}

ll getBIT(int t, int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[t][i];
    return res;
}

ii getLefRig(int t, int key) {
    auto it = S[t].lower_bound({key + 1, 0});
    --it;
    if (it->first == key) {
        int res2 = it->second - it->first + 1;
        --it;
        return {it->second - it->first + 1, res2};
    }
    return {key - it->first, it->second - key + 1};
}

void downOn(int t, int v, int a, int b, const Mults& flag) {
    tr[t][v] += flag.mult1 * (coef1[b] - coef1[a - 1]) +
            flag.mult2 * (coef2[b] - coef2[a - 1]) +
            flag.mult3 * (b - (a - 1));
    fl[t][v] += flag;
}

void downSums(int t, int v, int l, int r, int m) {
    if (!fl[t][v].Zero()) {
        downOn(t, 2 * v, l, m, fl[t][v]);
        downOn(t, 2 * v + 1, m + 1, r, fl[t][v]);
        fl[t][v] = {0, 0, 0};
    }
}

void addSums(int t, int v, int l, int r, int a, int b, const Mults& mults) {
    if (l == a && r == b)
        downOn(t, v, l, r, mults);
    else {
        int m = l + r >> 1;
        downSums(t, v, l, r, m);
        if (a <= m)
            addSums(t, 2 * v, l, m, a, min(m, b), mults);
        if (m + 1 <= b)
            addSums(t, 2 * v + 1, m + 1, r, max(m + 1, a), b, mults);
        tr[t][v] = tr[t][2 * v] + tr[t][2 * v + 1];
    }
}

ll getSums(int t, int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        return tr[t][v];
    int m = l + r >> 1;
    downSums(t, v, l, r, m);
    ll res = 0;
    if (a <= m)
        res += getSums(t, 2 * v, l, m, a, min(m, b));
    if (m + 1 <= b)
        res += getSums(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
    return res;
}

void Add(int t, int val, int delt) {
    addSums(t, 1, 1, n[t], 1, val, {delt * val, -delt, 0});
    if (val < n[t]) {
        ll tot = static_cast<ll>(val) * (val + 1) / 2;
        addSums(t, 1, 1, n[t], val + 1, n[t], {0, 0, delt * tot});
    }
    int oth = 1 - t;
    ll sum = getSums(oth, 1, 1, n[oth], 1, min(n[oth], val));
    if (n[oth] < val)
        sum += (val - n[oth]) * getSums(oth, 1, 1, n[oth], n[oth], n[oth]);
    res += delt * sum;
}

void changeInterval(int t, int l, int val) {
    if (l == 1) {
        addBIT(t, 1, val);
        return;
    }
    if (l > n[t]) return;
    auto [lef, rig] = getLefRig(t, l);
    ll lefVal = getBIT(t, l - 1);
    ll rigVal = getBIT(t, l);
    if (lefVal == rigVal && lefVal != rigVal + val) {
        Add(t, lef, -1);
        Add(t, rig, -1);
        Add(t, lef + rig, 1);
        S[t].erase({l - lef, l - 1});
        S[t].erase({l, l + rig - 1});
        S[t].insert({l - lef, l + rig - 1});
    } else if (lefVal != rigVal && lefVal == rigVal + val) {
        Add(t, lef, 1);
        Add(t, rig, 1);
        Add(t, lef + rig, -1);
        S[t].erase({l - lef, l + rig - 1});
        S[t].insert({l - lef, l - 1});
        S[t].insert({l, l + rig - 1});
    }
    addBIT(t, l, val);
}

void changeIntervals(int t, int l, int r, int val) {
    changeInterval(t, l, val);
    changeInterval(t, r + 1, -val);
}

int main() {
    for (int i = 1; i < Maxn; i++) {
        coef1[i] = coef1[i - 1] + i;
        coef2[i] = coef2[i - 1] + static_cast<ll>(i) * (i - 1) / 2;
    }
    scanf("%d %d %d", &n[0], &n[1], &q);
    for (int t = 0; t < 2; t++) {
        for (int i = 1; i <= n[t]; i++) {
            scanf("%d", &inp[t][i]);
            addBIT(t, i, inp[t][i] - inp[t][i - 1]);
        }
        for (int i = 1, j; i <= n[t]; i = j + 1) {
            j = i;
            while (j < n[t] && inp[t][j] != inp[t][j + 1])
                j++;
            S[t].insert({i, j});
            Add(t, j - i + 1, 1);
        }
    }
    printf("%lld\n", res);
    while (q--) {
        int typ, l, r, x;
        scanf("%d %d %d %d", &typ, &l, &r, &x);
        changeIntervals(typ - 1, l, r, x);
        printf("%lld\n", res);
    }
    return 0;
}
