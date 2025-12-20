#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        int res = 0;
        for (int i = 1; i < a.size(); i++)
            res += (k - a[i]) / a[0];
        cout << res << "\n";
    }
    return 0;
}
