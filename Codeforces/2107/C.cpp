#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 200005;

int T;
int n;
ll k;
char str[Maxn];
ll a[Maxn];
ll L[Maxn], R[Maxn];

void printYes()
{
    printf("Yes\n");
    for (int i = 1; i <= n; i++)
        printf("%lld%c", a[i], i + 1 <= n? ' ': '\n');
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &k);
        scanf("%s", str + 1);
        ll mx = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            if (str[i] == '0')
                a[i] = -Inf;
            L[i] = max(L[i - 1] + a[i], 0ll);
            mx = max(mx, L[i]);
        }
        if (mx > k) {
            printf("No\n");
            continue;
        }
        if (mx == k) {
            printYes();
            continue;
        }
        R[n + 1] = 0;
        for (int i = n; i > 0; i--)
            R[i] = max(R[i + 1] + a[i], 0ll);
        bool found = false;
        for (int i = 1; i <= n; i++)
            if (str[i] == '0') {
                found = true;
                a[i] = k - L[i - 1] - R[i + 1];
                break;
            }
        if (found)
            printYes();
        else printf("No\n");
    }
    return 0;
}
