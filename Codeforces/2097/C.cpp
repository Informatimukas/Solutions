#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void extendedGcd(ll a, ll& x, ll b, ll& y, ll& g) {
    if (a == 0) { x = 0; y = 1; g = b; }
    else {
        ll xx, yy;
        extendedGcd(b % a, xx, a, yy, g);
        x = yy - b / a * xx;
        y = xx;
    }
}

ll Solve(ll x, ll y, ll vx, ll vy, ll n) {
    ll val = vy * x - vx * y;
    if (val % n) return -1;
    val /= n;
    ll a, b, g;
    extendedGcd(vy, a, vx, b, g);
    if (val % g)
        return -1;
    ll md = vx / g;
    a %= md;
    val /= g;
    a = val % md * a % md;
    if (a <= 0) a += md;
    b = (a * vy - val * g) / vx;
    return a + b - 2 + (a + b) / 2 + abs(a - b) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y, vx, vy;
        cin >> n >> x >> y >> vx >> vy;
        cout << Solve(x, y, vx, vy, n) << "\n";
    }
    return 0;
}
