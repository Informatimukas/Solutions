#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, d;
        cin >> n >> k >> d;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int res = n;
        for (int i = 0; i + d <= n; i++)
            res = min(res, static_cast<int>(set(a.begin() + i, a.begin() + i + d).size()));
        cout << res << "\n";
    }
    return 0;
}
