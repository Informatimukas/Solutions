#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int lef = 1, rig = 10000;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            int res1 = mid * (x + y);
            int res2 = mid * x + max(0, (mid - z) * 10 * y);
            if (max(res1, res2) >= n)
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
