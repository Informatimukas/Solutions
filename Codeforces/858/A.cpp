#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll p = 1;
    while (k--)
        p *= 10;
    n = n / gcd(n, p) * p;
    cout << n << "\n";
    return 0;
}
