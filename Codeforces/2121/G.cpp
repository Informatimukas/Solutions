#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;

constexpr int Maxn = 400005;

int T;
int n, N;
char str[Maxn];
ill BIT[Maxn];

void Add(int x, int val) {
    for (int i = x + n + 1; i <= N; i += i & -i) {
        BIT[i].first++;
        BIT[i].second += val;
    }
}

ill Get(int x) {
    ill ans = ill(0, 0);
    for (int i = x + n + 1; i > 0; i -= i & -i) {
        ans.first += BIT[i].first;
        ans.second += BIT[i].second;
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        N = 2 * n + 1;
        fill_n(BIT, N + 1, ill(0, 0));
        scanf("%s", str + 1);
        Add(0, 0);
        int st = 0;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            st += str[i] == '1'? 1: -1;
            ill smaller = Get(st);
            ill all = Get(n);
            ill bigger = {all.first - smaller.first, all.second - smaller.second};
            res += ll(i) * i - ll(i) * (i - 1) / 2;
            res += ll(smaller.first) * st - smaller.second;
            res += bigger.second - ll(bigger.first) * st;
            Add(st, st);
        }
        printf("%lld\n", res / 2);
    }
    return 0;
}