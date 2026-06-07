#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector res(n + 1, 1000000000);
        res[0] = 0;
        for (int i = 0; i < n; i++) {
            res[i + 1] = min(res[i + 1], res[i] + (a[i] != b[i]));
            if (i + 2 <= n)
                res[i + 2] = min(res[i + 2], res[i] + (a[i] != a[i + 1]) + (b[i] != b[i + 1]));
        }
        cout << res[n] << "\n";
    }
    return 0;
}
