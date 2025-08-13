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
        int l = 0, r = n - 1;
        while (r - l + 1 >= 3) {
            if (a[l] < a[l + 1] && a[l + 1] < a[r] ||
                a[l] > a[l + 1] && a[l + 1] > a[r]) {
                cout << "LRL";
            } else cout << "LLR";
            l += 2;
            r--;
        }
        while (l <= r) {
            cout << "L";
            l++;
        }
        cout << "\n";
    }
    return 0;
}