#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 300005;
constexpr int Inf = 1000000000;

struct pos {
    int best[2];
    int all;
    int flag;
    int res;
};

struct segtree {
    vector<pos> st;
    int n;
    segtree() {}
    segtree(const vector<int> &un) {

    }
};

int T;
int n, q;
int a[Maxn];
vector<int> un[Maxn];
int qi[Maxn], qx[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++)
            un[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            un[a[i]].push_back(i);
            un[a[i]].push_back(i - 1);
        }
        for (int i = 1; i <= q; i++) {
            scanf("%d %d", &qi[i], &qx[i]);
            un[qx[i]].push_back(qi[i]);
            un[qx[i]].push_back(qi[i] - 1);
        }
        for (int i = 1; i <= n; i++) {
            ranges::sort(un[i]);
            un[i].erase(ranges::unique(un[i]).begin(), un[i].end());
        }
    }
    return 0;
}
