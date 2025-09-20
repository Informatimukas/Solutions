#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (a == b || a == b + 1 || b == 1)
            cout << "-1\n";
        else if (a < b)
            cout << "2\n";
        else cout << "3\n";
    }
    return 0;
}