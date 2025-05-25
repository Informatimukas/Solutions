#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;

const int Maxn = 100005;

int n;
char str[Maxn];
uint dp[2][Maxn];
int cur;
int len[Maxn];

int main()
{
    scanf("%d", &n);
    if (n % 2) {
        printf("0\n");
        return 0;
    }
    scanf("%s", str);
    reverse(str, str + n);
    int was = 0;
    for (int i = 0; i < n; i++)
        was += str[i] != '?';
    int lim = n / 2;
    if (was > lim) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < lim; i++)
        len[i] = i + 1;
    for (int i = lim; i < n; i++)
        len[i] = n - 1 - i;
    dp[cur][0] = 1;
    for (int i = 0; i < n; i++, cur = !cur) {
        dp[!cur][0] = dp[cur][1];
        for (int j = 0; j <= len[i]; j++) {
            dp[!cur][j] = dp[cur][j + 1];
            if (str[i] == '?')
                dp[!cur][j] += dp[cur][j - 1];
        }
        dp[!cur][len[i] + 1] = dp[!cur][len[i] + 2] = 0;
    }
    uint res = dp[cur][0];
    for (int i = 0; i < lim - was; i++)
        res *= uint(25);
    cout << res << "\n";
    return 0;
}
