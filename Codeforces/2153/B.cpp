#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, y, z;
        cin >> x >> y >> z;
        int a = x | z;
        int b = x | y;
        int c = y | z;
        if ((a & b) == x && (b & c) == y && (a & c) == z)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}