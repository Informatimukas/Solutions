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
        cout << (x % y == 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
