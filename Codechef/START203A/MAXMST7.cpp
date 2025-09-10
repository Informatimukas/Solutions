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
        vector<int> w(n * (n - 1) / 2);
        for (auto& x : w)
            cin >> x;
        ranges::sort(w);
        int res = 0, pnt = 0;
        for (int i = 2; i <= n; i++) {
            res += w[pnt++];
            for (int j = 2; j < i; j++)
                pnt++;
        }
        cout << res << "\n";
    }
    return 0;
}
