#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

bool Solve()
{
    for (int i = 0; i + 1 < n; i++)
        if (a[i] == 0 && a[i + 1] == 0)
            return false;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum < n;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve()? "NO": "YES");
    }
	return 0;
}
