#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> b(n);
        int mn = numeric_limits<int>::max();
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (mn < b[i] / 2 + 1)
                ok = false;
            mn = min(mn, b[i]);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
