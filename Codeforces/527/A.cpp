#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Count(ll x, ll y) { return x ? y / x + Count(y % x, x): 0; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    cout << Count(a, b) << "\n";
    return 0;
}
