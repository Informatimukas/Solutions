#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector B(n, vector<int>(m));
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> B[i][j];
                sum += B[i][j];
            }
        int nd = sum / 2;
        ll res = static_cast<ll>(nd) * (sum - nd);
        int r = 0, c = m;
        while (nd > 0) {
            if (c == 0) {
                r++;
                c = m;
            }
            nd -= B[r][--c];
            if (nd == 0)
                break;
        }
        cout << res << "\n";
        for (int i = 0; i < r; i++)
            cout << "D";
        for (int j = 0; j < c; j++)
            cout << "R";
        cout << "D";
        for (int j = c; j < m; j++)
            cout << "R";
        for (int j = r + 1; j < n; j++)
            cout << "D";
        cout << "\n";
    }
    return 0;
}
