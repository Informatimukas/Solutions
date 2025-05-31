#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int T;
int n;
int mx[Maxn], my[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        multiset <int> X, Y;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &mx[i], &my[i]);
            X.insert(mx[i]);
            Y.insert(my[i]);
        }
        if (n == 1) {
            printf("1\n");
            continue;
        }
        ll res = Inf;
        for (int i = 0; i < n; i++) {
            X.erase(X.find(mx[i]));
            Y.erase(Y.find(my[i]));
            ll a = ll(*X.rbegin() - *X.begin() + 1);
            ll b = ll(*Y.rbegin() - *Y.begin() + 1);
            if (a * b > n - 1)
                res = min(res, a * b);
            else res = min(res, min((a + 1) * b, a * (b + 1)));
            X.insert(mx[i]);
            Y.insert(my[i]);
        }
        printf("%lld\n", res);
    }
	return 0;
}
