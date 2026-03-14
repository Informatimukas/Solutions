#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> c(n), p(n);
        for (int i = 0; i < n; i++)
            cin >> c[i] >> p[i];
        vector<ld> best(n + 1);
        best[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            best[i] = max(c[i] + (1 - p[i] / 100.0l) * best[i + 1], best[i + 1]);
        cout << fixed << setprecision(10) << best[0] << "\n";
    }
    return 0;
}
