#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll n;
        ll m;
        cin >> n >> m;
        ll res = 0;
        ll cur = 1;
        while (true) {
            ll pw = cur % m * 10 % m;
            pw = (pw + m - 1) % m;
            ll good = m / __gcd(pw, m);
            ll special;
            bool lst = false;
            if (cur <= n / 10) {
                special = 9 * cur;
                cur *= 10;
            } else {
                special = n - cur + 1;
                lst = true;
            }
            res = (res + special % mod * (n / good % mod)) % mod;
            if (lst)
                break;
        }
        cout << res << "\n";
    }
    return 0;
}
