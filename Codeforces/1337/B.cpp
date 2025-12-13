#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, n, m;
        cin >> x >> n >> m;
        bool res = false;
        for (int i = 0; i <= n; i++) {
            if (x - 10 * m <= 0)
                res = true;
            x = x / 2 + 10;
        }
        cout << (res ? "YES" : "NO") << "\n";
    }
    return 0;
}
