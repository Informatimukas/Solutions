#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        int zers = 0, ones = 0;
        for (int i = 0; i < n; i++)
            if (str[i] == '1') ones++;
            else zers++;
        int nd = (n - 2 * k) / 2;
        if (nd <= ones && nd <= zers && nd % 2 == ones % 2)
            printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
