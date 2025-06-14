#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

constexpr int Maxn = 500005;
constexpr int Maxm = 1048576;

struct event {
    int x;
    int delt;
    ii ab;
    bool operator<(const event &oth) const {
        if (x != oth.x)
            return x < oth.x;
        return delt < oth.delt;
    }
};

int T;
int n;
int a[Maxn];
int st[Maxm], flag[Maxm];

void downOn(int v, int f) {
    st[v] += f;
    flag[v] += f;
}

void Down(int v) {
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

void Clear(int v, int l, int r) {
    st[v] = flag[v] = 0;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

void Union(int v) {
    st[v] = max(st[2 * v], st[2 * v + 1]);
}

void Add(int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b) downOn(v, delt);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Add(2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        Union(v);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        vector<ii> big;
        for (int i = n - 1; i >= 0; i--)
            if (big.empty() || a[i] > big.back().first)
                big.emplace_back(a[i], i);
        vector<ii> small;
        vector<event> E;
        int res = 1;
        for (int i = 0; i < n; i++) {
            if (i == big.back().second)
                big.pop_back();
            int ind1 = partition_point(small.begin(), small.end(),
                    [&](const ii &x) { return x.first >= a[i]; }) - small.begin();
            int ind2 = lower_bound(big.begin(), big.end(), ii{a[i] + 1, 0}) - big.begin();
            if (ind1 < small.size() && ind2 < big.size()) {
                E.push_back({ind1, 1, {ind2, big.size() - 1}});
                E.push_back({static_cast<int>(small.size()), -1, {ind2, big.size() - 1}});
            }
            if (small.empty() || a[i] < small.back().first)
                small.emplace_back(a[i], i);
            if (!small.empty() && !big.empty() && small.back().first < big.back().first)
                res = max(res, 2);
        }
        if (res == 2) {
            sort(E.begin(), E.end());
            Clear(1, 0, n - 1);
            for (auto &e : E) {
                Add(1, 0, n - 1, e.ab.first, e.ab.second, e.delt);
                res = max(res, st[1] + 2);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}