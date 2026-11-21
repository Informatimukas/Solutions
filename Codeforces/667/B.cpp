#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += a;
        mx = max(mx, a);
    }
    cout << mx - (sum - mx) + 1 << "\n";
    return 0;
}
