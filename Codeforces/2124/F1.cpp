#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int mod = 998244353;
constexpr int Maxn = 105;

int T;
int n, m;
vector<int> my[Maxn];
int dp[Maxn];
bool ok[Maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            my[i].clear();
        for (int i = 0; i < m; i++) {
            int ind, x; scanf("%d %d", &ind, &x);
            ind--; x--;
            my[ind].push_back(x);
        }
        fill_n(dp, n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int l = 1; i + l <= n; l++) {
                fill_n(ok, l, true);
                for (int j = i; j < i + l; j++)
                    for (auto val: my[j])
                        ok[(val - (j - i) + l) % l] = false;
                int cnt = count(ok, ok + l, true);
                printf("i = %d, l = %d, cnt = %d, dpi = %d\n", i, l, cnt, dp[i]);
                dp[i + l] = (dp[i + l] + static_cast<ll>(dp[i]) * cnt) % mod;
            }
        printf("%d\n", dp[n]);
    }
    return 0;
}
