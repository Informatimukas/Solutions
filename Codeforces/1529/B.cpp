#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 100005;
constexpr int Inf = 1000000007;

int T;
int n;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector<int> seq;
        int was = Inf;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] <= 0) seq.push_back(a[i]);
            else was = min(was, a[i]);
        }
        ranges::sort(seq);
        bool ok = was < Inf;
        for (int i = 0; i + 1 < seq.size(); i++)
            if (seq[i + 1] - seq[i] < was) {
                ok = false;
                break;
            }
        int res = seq.size();
        res += ok;
        printf("%d\n", res);
    }
    return 0;
}
