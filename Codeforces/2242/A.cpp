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
        ranges::sort(a, greater());
        if (a[0] >= 3 || a.size() > 1 && a[1] >= 2)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
