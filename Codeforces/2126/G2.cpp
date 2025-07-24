#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;
constexpr int Maxm = 524288;

int T;
int n;
ii a[Maxn];
int flag[Maxm];
ii st[Maxm];

void downOn(int v, int f) {
    flag[v] += f;
    st[v].first += f;
    st[v].second += f;
}

void Down(int v) {
    if (flag[v]) {
        downOn(2 * v, flag[v]);
        downOn(2 * v + 1, flag[v]);
        flag[v] = 0;
    }
}

ii Union(const ii& a, const ii& b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

void Create(int v, int l, int r) {
    flag[v] = 0;
    if (l == r) st[v] = {l, l};
    else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void Update(int v, int l, int r, int a, int b) {
    if (l == a && r == b)
        downOn(v, -2);
    else {
        Down(v);
        int m = l + r >> 1;
        if (a <= m) Update(2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

ii Get(int v, int l, int r, int a, int b) {
    if (l == a && r == b) return st[v];
    Down(v);
    int m = l + r >> 1;
    if (b <= m) return Get(2 * v, l, m, a, b);
    if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
    return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i].second = i;
        }
        Create(1, 0, n);
        sort(a + 1, a + n + 1);
        int res = 0, l = 1;
        for (int r = 1; r <= n; r++) {
            while (l < r) {
                int ind = a[l].second;
                if (Get(1, 0, n, ind, n).second -
                    Get(1, 0, n, 0, ind - 1).first >= 0)
                    break;
                l++;
            }
            res = max(res, a[r].first - a[l].first);
            Update(1, 0, n, a[r].second, n);
        }
        printf("%d\n", res);
    }
    return 0;
}
