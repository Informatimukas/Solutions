#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        ll best = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            ll cand = sum;
            for (int j = i; j < n && j - i + 1 <= 30; j++)
                cand += a[j] / (1 << (j - i + 1));
            best = max(best, cand);
            sum += a[i] - k;
        }
        best = max(best, sum);
        printf("%lld\n", best);
    }
    return 0;
}