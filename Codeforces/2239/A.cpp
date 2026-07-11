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
        int xr = 0;
        for (auto& x : a) {
            cin >> x;
            xr ^= x;
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        if (xr == 0) {
            cout << "1\n";
            continue;
        }
        int res = 0;
        for (auto x : a)
            if ((xr ^ x) <= x)
                res++;
        cout << res << "\n";
    }
    return 0;
}
