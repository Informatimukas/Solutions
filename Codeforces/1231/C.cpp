#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector B(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            int lim = 1000000000;
            if (j + 1 < m)
                lim = min(lim, B[i][j + 1]);
            if (i + 1 < n)
                lim = min(lim, B[i + 1][j]);
            if (B[i][j] == 0)
                B[i][j] = lim - 1;
            if (B[i][j] >= lim || B[i][j] <= 0) {
                cout << "-1\n";
                return 0;
            }
            res += B[i][j];
        }
    cout << res << "\n";
    return 0;
}
