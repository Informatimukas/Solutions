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
        int cur = 0;
        for (auto x : a | views::reverse)
            cur = 2 * x - cur;
        cout << cur / 2 << "\n";
    }
    return 0;
}
