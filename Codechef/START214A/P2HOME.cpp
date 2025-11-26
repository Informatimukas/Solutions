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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        bool ok = true;
        for (int i = 0; i + 1 < n; i++)
            if ((a[i] < a[i + 1]) != (b[i] < b[i + 1])) {
                ok = false;
                break;
            }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
