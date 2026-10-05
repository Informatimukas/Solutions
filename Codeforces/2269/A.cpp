#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int res = 2 * (k - 1) + (1 << (n - k + 1));
        cout << res << "\n";
    }
    return 0;
}
