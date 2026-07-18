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
        ll n;
        cin >> n;
        ll res = 0;
        for (ll i = 1; i <= n; i++)
            res += n / i * (n / i);
        cout << res << "\n";
    }
    return 0;
}
