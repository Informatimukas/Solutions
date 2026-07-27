#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld x, y;
    cin >> x >> y;
    ld a = x * log(y), b = y * log(x);
    if (fabs(a - b) < 1e-14l)
        cout << "=\n";
    else if (a > b)
        cout << "<\n";
    else cout << ">\n";
    return 0;
}
