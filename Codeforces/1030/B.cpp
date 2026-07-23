#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int a = x + y, b = x - y;
        if (d <= a && a <= 2 * n - d && -d <= b && b <= d)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
