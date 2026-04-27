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
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int f = i == 0 ? 1 : __gcd(a[i - 1], a[i]);
            int s = i == n - 1 ? 1 : __gcd(a[i], a[i + 1]);
            int lcm = f / __gcd(f, s) * s;
            if (lcm != a[i] && lcm < b[i])
                res++;
        }
        cout << res << "\n";
    }
    return 0;
}
