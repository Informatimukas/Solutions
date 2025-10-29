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
        int n;
        cin >> n;
        ll g = 0;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            g = __gcd(g, a);
        }
        ll i = 2;
        while (__gcd(i, g) > 1)
            i++;
        cout << i << "\n";
    }
    return 0;
}
