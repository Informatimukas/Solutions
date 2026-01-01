#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (mx > a)
                ++res;
            else mx = a;
        }
        cout << res << "\n";
    }
    return 0;
}