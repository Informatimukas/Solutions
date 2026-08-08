#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l;
    cin >> n >> l;
    ld mult = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mult += a;
    }
    mult /= n;
    vector dp1(2 * n + 1, vector(n + 1, 0.0l));
    for (int z = 1; z <= l; z++) {
        vector ndp1(2 * n + 1, vector(n + 1, 0.0l));
        vector ndp2(2 * n + 1, vector(n + 1, 0.0l));
        for (int i = 1; i <= 2 * n; i++)
            for (int j = 0; j <= n; j++) {
                if (j > 0)
                    ndp1[i][j] += static_cast<ld>(j) / i * (1 + ndp1[i - 1][j - 1]);
                if (j < i && j < n)
                    ndp1[i][j] += static_cast<ld>(i - j) / i * ndp2[i - 1][j + 1];
                if (j > 0) {
                    ndp2[i][j] += static_cast<ld>(1) / i * (1 + ndp1[i - 1][j - 1]);
                    if (z > 1)
                        ndp2[i][j] += static_cast<ld>(j - 1) / i * (1 + dp1[i - 1][j - 1]);
                }
                if (j < i && j < n)
                    ndp2[i][j] += static_cast<ld>(i - j) / i * dp1[i - 1][j + 1];
            }
        dp1 = ndp1;
    }
    cout << fixed << setprecision(10) << mult * dp1[2 * n][0] << "\n";
    return 0;
}
