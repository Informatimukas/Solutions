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
        int res = n;
        for (int i = 0; i < n; i++) {
            int small = 0, big = 0;
            for (auto x : a)
                if (x < a[i])
                    small++;
                else if (x > a[i])
                    big++;
            res = min(res, max(small, big));
        }
        cout << res << "\n";
    }
    return 0;
}
