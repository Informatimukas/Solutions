#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        int res = 0;
        set <int> S;
        for (int i = 0; i < n; i++) {
            int A = i;
            int B = n - 1 - i;
            if (abs(A - B) <= k + 1)
                S.insert(a[i]);
            if (i + 1 < n && a[i] < a[i + 1]) {
                A = i + 1;
                B = n - 1 - i;
                if (abs(A - B) <= k)
                    res += a[i + 1] - a[i] - 1;
            }
        }
        res += S.size();
        printf("%d\n", res);
    }
    return 0;
}
