#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0, lst = 0;
        scanf("%s", str);
        for (int i = 0; i < n; i++) {
            int cur = str[i] - '0';
            if (lst != cur) {
                res++;
                lst = cur;
            }
        }
        if (res == 2) res = 1;
        else if (res > 2) res -= 2;
        res += n;
        printf("%d\n", res);
    }
    return 0;
}
