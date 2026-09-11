#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(int key, int a, int d, int g, ll x) {
    a |= key;
    a %= d;
    if (a % g)
        return -1;
    ll nd = (d - a) % d;
    nd = nd * x % d;
    return nd << 30 | key;
}

void gcd(ll a, ll& x, ll b, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return;
    }
    ll xx, yy;
    gcd(b % a, xx, a, yy);
    x = yy - b / a * xx;
    y = xx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, d;
        cin >> a >> b >> d;
        int oth = 1 << 30;
        int g = gcd(1 << 30, d);
        int noth = oth / g, nd = d / g;
        ll x, y;
        gcd(noth, x, nd, y);
        x %= nd;
        if (x < 0)
            x += nd;
        cout << "g = " << g << ", x = " << x << endl;
        bool bad = false;
        for (int i = 0; 1 << i < g; i++) {
            if ((a & 1 << i) || (b & 1 << i)) {
                bad = true;
                break;
            }
        }
        if (bad) {
            cout << "-1\n";
            continue;
        }
        int key = 0;
        cout << "from = " << __builtin_popcount(g - 1) << endl;
        for (int i = __builtin_popcount(g - 1); i < 30; i++)
            key |= 1 << i;
        ll res = Solve(key, a, d, g, x);
        ll ta = (res | a) % d, tb = (res | b) % d;
        cout << res << "\n";
        cout << " " << ta << " " << tb << endl;
    }
    return 0;
}
