#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 100005;

int T;
int n, m;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        sort(a, a + m);
        vector<ii> res;
        int l = 0, r = m - 1;
        while (l <= r) {
            res.emplace_back(a[l], a[r]);
            res.emplace_back(a[r], a[l]);
            l++; r--;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                printf("%d %d%c", res[i].first, res[i].second, j + 1 < 3 ? ' ' : '\n');
    }
    return 0;
}