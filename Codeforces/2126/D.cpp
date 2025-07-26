#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

constexpr int Maxn = 100005;

int T;
int n, k;
iii seq[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d %d %d", &seq[i].second.first, &seq[i].second.second, &seq[i].first);
        sort(seq, seq + n);
        for (int i = 0; i < n; i++)
            if (seq[i].second.first <= k && k <= seq[i].second.second)
                k = max(k, seq[i].first);
        printf("%d\n", k);
    }
    return 0;
}