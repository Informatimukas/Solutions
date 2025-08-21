#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll a, b, k;
        cin >> a >> b >> k;
        ll g = __gcd(a, b);
        a /= g; b /= g;
        if (a <= k && b <= k)
            cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}