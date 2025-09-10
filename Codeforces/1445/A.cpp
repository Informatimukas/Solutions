#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (a[i] + b[n - 1 - i] > x) {
                ok = false;
                break;
            }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}