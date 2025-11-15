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
        ll mx = 0, best = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            sum += a;
            best = max(best, static_cast<ll>(i) * i + i - sum + mx);
            mx = max(mx, sum + i + 1 - static_cast<ll>(i + 1) * (i + 1));
        }
        cout << sum + best << "\n";
    }
    return 0;
}
