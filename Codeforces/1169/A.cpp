#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    for (int i = 0; i < n; i++) {
        if (a == b) {
            cout << "YES\n";
            return 0;
        }
        if (a == x || b == y)
            break;
        a = a % n + 1;
        b = 1 + (b + n - 2) % n;
    }
    cout << "NO\n";
    return 0;
}