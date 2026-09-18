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
        vector<int> a(n);
        int res = 0;
        for (auto& x : a) {
            cin >> x;
            res += x == 0;
        }
        if (res <= 1)
            cout << "-1\n";
        else cout << (a[0] != 0) + (a[n - 1] != 0) << "\n";
    }
    return 0;
}
