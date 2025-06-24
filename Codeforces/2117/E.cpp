#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
int a[Maxn];
int b[Maxn];

int Solve() {
    map<int, ii> M;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i])
            return i + 1;
        if (M.contains(a[i])) {
            auto &p = M[a[i]];
            if (i + 1 < p.first || p.second == 0)
                return i + 1;
        } else M[a[i]] = {i, 0};
        if (M.contains(b[i])) {
            auto &p = M[b[i]];
            if (i + 1 < p.first || p.second == 1)
                return i + 1;
        } else M[b[i]] = {i, 1};
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        printf("%d\n", Solve());
    }
    return 0;
}
