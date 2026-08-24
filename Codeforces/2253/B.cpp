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
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = a[n + 1] = 0;
        vector<int> L(n + 2);
        vector<int> R(n + 2);
        for (int i = 1; i <= n; i++)
            L[i] = L[i - 1] + (a[i] != a[i - 1]);
        for (int i = n; i >= 1; i--)
            R[i] = R[i + 1] + (a[i] != a[i + 1]);
        int res = L[n];
        for (int i = 1; i + 1 <= n; i++)
            if (a[i] != a[i + 1])
                res = max(res, L[i - 1] + R[i + 2] + (a[i] != a[i + 2]) + (a[i - 1] != a[i + 1]));
        cout << res << "\n";
    }
    return 0;
}
