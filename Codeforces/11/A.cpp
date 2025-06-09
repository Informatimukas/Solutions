#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;

int n, d;
int a;

int main()
{
    cin >> n >> d;
    ll res = 0, lst = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (lst < a) lst = a;
        else {
            ll add = (lst - a) / d + 1;
            res += add;
            lst = a + d * add;
        }
    }
    cout << res << "\n";
    return 0;
}
