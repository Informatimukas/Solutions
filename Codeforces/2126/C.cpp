#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;

int T;
int n, k;
int a[Maxn];
vector<int> seq;

bool Solve() {
    int cur = 0;
    for (int i = 0; i + 1 < seq.size(); i++) {
        int nd = seq[i + 1] - seq[i];
        if (seq[i] - cur >= nd)
            cur += nd;
        else return false;
    }
    return true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        seq.clear();
        for (int i = 1; i <= n; i++)
            if (i == k || a[i] > a[k])
                seq.push_back(a[i]);
        ranges::sort(seq);
        printf("%s\n", Solve() ? "YES" : "NO");
    }
    return 0;
}