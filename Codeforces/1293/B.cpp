#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ld res = 0;
    for (int i = 1; i <= n; i++)
        res += 1.0l / i;
    cout << fixed << setprecision(10) << res << "\n";
    return 0;
}
