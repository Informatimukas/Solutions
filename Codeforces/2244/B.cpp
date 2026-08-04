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
        ll res = 0;
        bool ans = true;
        for (int i = 1; i <= n; i++) {
            ll a;
            cin >> a;
            res += a - i;
            if (res < 0)
                ans = false;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
