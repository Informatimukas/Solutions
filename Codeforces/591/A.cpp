#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int l;
    int p, q;
    cin >> l >> p >> q;
    cout << fixed << setprecision(5) << static_cast<ld>(l) * p / (p + q) << "\n";
    return 0;
}
