#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, n;
        cin >> x >> n;
        int res = 0;
        while (n) {
            res += x;
            n--;
            x = -x;
        }
        cout << res << "\n";
    }
    return 0;
}