#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int res = max(max(x, a - 1 - x) * b, max(y, b - 1 - y) * a);
        cout << res << "\n";
    }
    return 0;
}
