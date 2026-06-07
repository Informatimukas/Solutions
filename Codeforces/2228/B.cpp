#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        int res = n <= 3 ? 1 : k + min(abs(x1 - x2), n - abs(x1 - x2));
        cout << res << "\n";
    }
    return 0;
}
