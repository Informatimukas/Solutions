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
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            if ((a.back() & 1 << i) && !(a[0] & 1 << i)) {
                res |= (1 << (i + 1)) - 1;
                break;
            }
            if (a[0] & 1 << i)
                res |= 1 << i;
        }
        cout << res << "\n";
    }
    return 0;
}
