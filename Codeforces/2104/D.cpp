#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 400005;
const int Maxm = 7000005;

int T;
int n;
int a[Maxn];
bool prime[Maxm];
ll nd[Maxm];
int nlen;

int main()
{
    fill(prime + 2, prime + Maxm, true);
    for (int i = 2; i < Maxm; i++) if (prime[i]) {
        nd[nlen + 1] = nd[nlen] + i;
        nlen++;
        for (int j = i + i; j < Maxm; j += i)
            prime[j] = false;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll has = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            has += a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            if (nd[n - i] <= has) {
                printf("%d\n", i);
                break;
            } else has -= a[i];
    }
	return 0;
}
