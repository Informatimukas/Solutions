#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (y > x + 1) {
            cout << "-1\n";
            continue;
        }
        int res = x;
        if (x % 2 != y % 2)
            res++;
        cout << res << "\n";
    }
    return 0;
}
