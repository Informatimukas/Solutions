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
        int mx = 0;
        for (int i = 0; i < n; i += 2)
            mx = max(mx, a[i + 1] - a[i]);
        cout << mx << "\n";
    }
    return 0;
}
