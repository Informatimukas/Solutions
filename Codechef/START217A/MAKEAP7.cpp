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
        vector<int> a(n);
        int g = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i)
                g = __gcd(g, a[i] - a[i - 1]);
        }
        int res = 0;
        for (int i = 0; i + 1 < n; i++)
            res += (a[i + 1] - a[i]) / g - 1;
        cout << res << "\n";
    }
    return 0;
}
