#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n, a, b;
        cin >> n >> a >> b;
        b = min(b, 3 * a);
        ll res = n / 3 * b;
        n %= 3;
        if (n > 0)
            res += min(b, n * a);
        cout << res << "\n";
    }
    return 0;
}
