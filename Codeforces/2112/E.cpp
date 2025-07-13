#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int Maxn = 500005;
constexpr int Inf = 1000000000;

vector<int> dvs[Maxn];
int dp[Maxn];
int T;
int m;

int main() {
    for (int i = 2; i < Maxn; i++)
        for (int j = i + i; j < Maxn; j += i)
            dvs[j].push_back(i);
    dp[1] = 1;
    for (int i = 2; i < Maxn; i++) {
        dp[i] = Inf;
        for (int j : dvs[i])
            dp[i] = min(dp[i], dp[j] + dp[i / j] - 1);
        if (i > 2)
            dp[i] = min(dp[i], dp[i - 2] + 1);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        printf("%d\n", dp[m] >= Inf? -1: dp[m]);
    }
    return 0;
}
