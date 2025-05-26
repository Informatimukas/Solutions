#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 205;

int n;
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    ll sum = 0;
    int mn = 1000000006;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
            sum += B[i][j];
            if (i + j == n - 1)
                mn = min(mn, B[i][j]);
        }
    printf("%lld\n", sum - ll(mn));
	return 0;
}
