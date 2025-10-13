#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        k = n * n - k;
        if (k == 1) {
            cout << "NO\n";
            continue;
        }
        vector B(n, string(n, 'R'));
        int r = 0;
        while (k >= n) {
            B[r][n - 1] = 'L';
            k -= n;
            r++;
        }
        if (k == 1)
            B[r][0] = 'U';
        else if (k > 0)
            B[r][k - 1] = 'L';
        cout << "YES\n";
        for (auto& x : B)
            cout << x << "\n";
    }
    return 0;
}
