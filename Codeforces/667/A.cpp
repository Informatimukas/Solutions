#include <bits/stdc++.h>
using namespace std;

using ld = long double;

constexpr ld pi = acos(-1.0l);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld d, h, v, e;
    cin >> d >> h >> v >> e;
    ld a = h * (d / 2) * (d / 2) * pi;
    ld b = v - e * (d / 2) * (d / 2) * pi;
    if (b < 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << fixed << setprecision(10) << a / b << "\n";
    return 0;
}
