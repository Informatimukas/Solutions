#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        string s;
        cin >> s;
        if (s[0] != '1' || s[n - 1] != '1') {
            cout << "-1\n";
            continue;
        }
        ll res = 1;
        for (int i = 0; i + 1 < n; i++)
            if (s[i] == '1') {
                if (c % 2 == 0)
                    c /= 2;
                res = 2 * res % mod;
            } else {
                c /= __gcd(i, c);
                res = res * i % mod;
            }
        if (c == 1)
            res = -1;
        cout << res << "\n";
    }
    return 0;
}
