#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const ll Inf = 1000000000000000000ll;

int T;
int n;
int a[Maxn];
ll dp[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            dp[i] = ll(i) * (1 + a[i]);
        ll res = Inf;
        for (int i = 0; i < n; i++) {
            res = min(res, dp[i] + n - 1 - i + a[i] + ll(n - 1 - i) * (a[i] + 1));
            for (int j = i + 1; j < n; j++)
                if (a[i] == a[j])
                    dp[j] = min(dp[j], dp[i] + a[i] + ll(j - 1 - i) * (a[i] + 1));
                else dp[j] = min(dp[j], dp[i] + j - 1 - i + a[i] + ll(j - 1 - i) * (a[i] + 1));
        }
        printf("%lld\n", res);
    }
    return 0;
}
