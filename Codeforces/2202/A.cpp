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
        int tot = x + y;
        if (tot > 0 && tot % 3 == 0) {
            tot /= 3;
            if (-tot <= y && y <= tot)
                cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }
    return 0;
}
