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
        ranges::sort(a);
        bool ok = true;
        for (int i = 1; i + 1 < a.size(); i += 2)
            if (a[i] < a[i + 1]) {
                ok = false;
                break;
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
