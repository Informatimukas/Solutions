#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (auto& y : c)
        cin >> y;
    vector<ld> spec(n);
    for (int i = 0; i < n; i++)
        spec[i] = static_cast<ld>(x) * (2 * n - i) / (2 * n - 2 * i);
    ld res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res += min(static_cast<ld>(c[i]), spec[j]) / n;
    cout << fixed << setprecision(15) << res << "\n";
    return 0;
}
