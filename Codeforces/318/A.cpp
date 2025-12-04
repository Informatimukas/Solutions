#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    ll odd = (n + 1) / 2;
    if (k <= odd)
        cout << k * 2 - 1 << "\n";
    else {
        k -= odd;
        cout << 2 * k << "\n";
    }
    return 0;
}