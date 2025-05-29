#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];
vector <int> V[2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        V[0].clear();
        V[1].clear();
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            V[a[i] % 2].push_back(i);
        int res = 0;
        for (int i = 0; i < 2; i++)
            if (!V[i].empty())
                res = max(res, V[i].back() - V[i][0] + 1);
        printf("%d\n", n - res);
    }
	return 0;
}
