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
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        ll resa = m / a * 6;
        ll resb = m / b * 6;
        ll resc = m / c * 6;
        ll lcmab = a / __gcd(a, b) * b;
        ll lcmac = a / __gcd(a, c) * c;
        ll lcmbc = b / __gcd(b, c) * c;
        ll lcm = lcmab / __gcd(lcmab, c) * c;
        resa -= m / lcmab * 3;
        resa -= m / lcmac * 3;
        resb -= m / lcmab * 3;
        resb -= m / lcmbc * 3;
        resc -= m / lcmac * 3;
        resc -= m / lcmbc * 3;
        resa += m / lcm * 2;
        resb += m / lcm * 2;
        resc += m / lcm * 2;
        cout << resa << " " << resb << " " << resc << "\n";
    }
    return 0;
}
