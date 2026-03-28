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
        int lef = -1, rig = -1;
        int res = 0;
        for (auto& x : a) {
            cin >> x;
            if (x <= lef || x > rig + 1) {
                ++res;
                lef = rig = x;
            } else rig = x;
        }
        cout << res << "\n";
    }
    return 0;
}
