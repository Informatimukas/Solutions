#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (b % 2 == n % 2 && (b >= a || a % 2 == n % 2))
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}