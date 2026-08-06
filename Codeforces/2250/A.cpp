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
        if (n % 2) {
            cout << "NO\n";
            continue;
        }
        int lef = 0, rig = 2000000000;
        for (int i = 0; i < n; i += 2) {
            lef = max(lef, a[i + 1] + 1);
            rig = min(rig, a[i] - 1);
        }
        cout << (lef <= rig ? "YES" : "NO") << "\n";
    }
    return 0;
}
