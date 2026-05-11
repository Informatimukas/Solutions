#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ll sum = 0;
    int g = 0;
    for (int i = 0; i + 1 < n; i++) {
        int d = abs(a[i] - a[i + 1]);
        sum += d;
        g = gcd(g, 2 * d);
    }
    if (g == 0)
        cout << a[n - 1] << "\n";
    else cout << (a[0] - 1) % g + 1 + sum << "\n";
    return 0;
}
