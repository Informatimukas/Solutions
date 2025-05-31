#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

vector <int> dvs[Maxn];
int lst[Maxn];
int dp[Maxn];

int Ask(int num, int q, int k)
{
    if (num == 1) return 0;
    if (lst[num] == q)
        return dp[num];
    lst[num] = q;
    dp[num] = Maxn;
    for (int i = 0; i < dvs[num].size() && dvs[num][i] <= k; i++)
        dp[num] = min(dp[num], Ask(num / dvs[num][i], q, k) + 1);
    return dp[num];
}

int Gcd(int x, int y) { return x? Gcd(y % x, x): y; }

int main()
{
    for (int i = 2; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            dvs[j].push_back(i);
    int T; scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        int g = Gcd(x, y);
        int res = Ask(y / g, tc, k) + Ask(x / g, tc, k);
        printf("%d\n", res >= Maxn? -1: res);
    }
	return 0;
}
