#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (x % 2 + y % 2 <= 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
