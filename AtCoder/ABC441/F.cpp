#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector L(n + 2, vector(m + 1, 0ll));
    vector R(n + 2, vector(m + 1, 0ll));
    vector<int> p(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> v[i];
        for (int j = 0; j < p[i]; j++)
            L[i][j] = L[i - 1][j];
        for (int j = p[i]; j <= m; j++)
            L[i][j] = max(L[i - 1][j], L[i - 1][j - p[i]] + v[i]);
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < p[i]; j++)
            R[i][j] = R[i + 1][j];
        for (int j = p[i]; j <= m; j++)
            R[i][j] = max(R[i + 1][j], R[i + 1][j - p[i]] + v[i]);
    }
    ll best = L[n][m];
    for (int i = 1; i <= n; i++) {
        bool goodWith = false, goodWithout = false;
        for (int j = 0; j <= m; j++) {
            if (L[i - 1][j] + R[i + 1][m - j] == best)
                goodWithout = true;
            if (j + p[i] <= m && L[i - 1][j] + R[i + 1][m - j - p[i]] + v[i] == best)
                goodWith = true;
        }
        if (goodWith && goodWithout)
            cout << "B";
        else if (goodWith)
            cout << "A";
        else cout << "C";
    }
    cout << "\n";
    return 0;
}
