#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 200005;

int T;
int n;
int freq[Maxn];
int res[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill_n(freq, n + 1, 0);
        fill_n(res, n + 1, 0);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            freq[a]++;
        }
        int tot = 0, spec = 0;
        for (int i = 0; i <= n; i++) {
            tot += freq[i];
            res[freq[i]]++;
            res[freq[i] + spec + n - tot + 1]--;
            if (freq[i] == 0) break;
            spec += freq[i] - 1;
        }
        int ways = 0;
        for (int i = 0; i <= n; i++) {
            ways += res[i];
            printf("%d%c", ways, i + 1 <= n? ' ': '\n');
        }
    }
    return 0;
}