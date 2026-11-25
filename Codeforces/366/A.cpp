#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= 4; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mn1 = min(a, b), mn2 = min(c, d);
        if (mn1 + mn2 <= n) {
            cout << i << " " << mn1 << " " << n - mn1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
