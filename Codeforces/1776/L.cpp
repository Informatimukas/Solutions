#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
char str[Maxn];
int p, m;
int q;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        if (str[i] == '+') p++;
        else m++;
    scanf("%d", &q);
    while (q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        bool yes = false;
        if (a == b)
            yes = p == m;
        else if (ll(b) * (m - p) % (a - b) == 0) {
            ll d = ll(b) * (m - p) / (a - b);
            if (d >= 0) yes = d <= p;
            else yes = -d <= m;
        }
        printf("%s\n", yes? "YES": "NO");
    }
    return 0;
}
