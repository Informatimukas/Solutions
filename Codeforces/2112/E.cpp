#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 500005;
constexpr int Inf = 1000000000;

vector<int> dvs[Maxn];
ll dp[Maxn];
int res[Maxn];
int mn[Maxn];
int T;
int m;

int main() {
    for (int i = 2; i < Maxn; i++)
        for (int j = i + i; j < Maxn; j += i)
            dvs[j].push_back(i);
    dp[1] |= 1ll << 1;
    for (int i = 2; i < Maxn; i++) {
        for (int j : dvs[i])
            for (int k = 1; k <= 30; k++)
                if (dp[j] & 1ll << k)
                    dp[i] |= dp[i / j] << k - 1;
        for (int j = 1; 1 << j < i; j++) {
            int ind = i - (1 << j);
            if (dp[ind] & 1ll << j)
                dp[i] |= 1ll << j + 1;
        }
        int b = 1;
        while (b <= 30 && !(dp[i] & 1ll << b))
            b++;
        res[i] = b;
        if (i <= 10) {
            printf("dp[%d] = %lld\n", i, dp[i]);
            printf("res[%d] = %d\n", i, res[i]);
        }
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        printf("%d\n", res[m]);
    }
    return 0;
}
