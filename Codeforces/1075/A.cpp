#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    ll r1 = max(x - 1, y - 1);
    ll r2 = max(n - x, n - y);
    if (r1 <= r2)
        cout << "White\n";
    else cout << "Black\n";
    return 0;
}
