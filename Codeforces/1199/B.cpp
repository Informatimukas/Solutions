#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ld h, l;
    cin >> h >> l;
    cout << fixed << setprecision(10) << (l * l - h * h) / (2 * h) << "\n";
    return 0;
}
