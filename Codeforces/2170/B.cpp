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
        int n;
        cin >> n;
        ll sum = 0;
        int nonzero = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            nonzero += a > 0;
        }
        int res = nonzero;
        if (sum - (n - 1) < res)
            res = sum - (n - 1);
        cout << res << "\n";
    }
    return 0;
}
