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
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res = max(res, min(i + 1, a[i]));
        cout << res << "\n";
    }
    return 0;
}
