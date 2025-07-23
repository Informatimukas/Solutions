#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

constexpr int Maxn = 200005;

int T;
int n;
int a[Maxn];

int Solve(int x) {
    int st = 0, mn = 0;
    vector<ii> seq;
    int res = 0;
    for (int i = 0; i < n; i++) {
        st += a[i] >= x? 1: -1;
        ii my = {a[i], mn};
        while (!seq.empty() && seq.back().first >= a[i])
            seq.pop_back();
        seq.emplace_back(my);
        mn = min(mn, st);
        int ind = ranges::partition_point(seq, [st](const ii &el) {
            return el.second > st;
        }) - seq.begin();
        if (ind < seq.size())
            res = max(res, x - seq[ind].first);
    }
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        for (int i = 1; i <= min(n, 100); i++)
            res = max(res, Solve(i));
        printf("%d\n", res);
    }
    return 0;
}
