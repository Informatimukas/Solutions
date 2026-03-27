#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;
    cout << fixed << setprecision(10) << (l - d) / (v1 + v2) << "\n";
    return 0;
}