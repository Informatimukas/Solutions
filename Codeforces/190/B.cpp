#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld X1, Y1, R1;
    ld X2, Y2, R2;
    cin >> X1 >> Y1 >> R1;
    cin >> X2 >> Y2 >> R2;
    ld dist = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
    ld res = 0.0l;
    if (dist >= R1 + R2)
        res = dist - R1 - R2;
    else if (R1 - dist >= R2)
        res = R1 - dist - R2;
    else if (R2 - dist >= R1)
        res = R2 - dist - R1;
    res /= 2.0;
    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}
