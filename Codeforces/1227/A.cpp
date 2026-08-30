#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int mn = Inf, mx = -Inf;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            mx = max(mx, a);
            mn = min(mn, b);
        }
        cout << max(mx - mn, 0) << "\n";
    }
    return 0;
}
