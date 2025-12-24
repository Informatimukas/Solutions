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
        int res = a[0], mn = 1000000000;
        for (int i = 0; i < n; i++)
            if (a[i] > a[0])
                mn = min(mn, a[i] - a[0]);
        res = max(res, mn);
        cout << res << "\n";
    }
    return 0;
}
