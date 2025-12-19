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
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = 1000000000;
            if (i)
                r[i] = min(r[i], a[i] - a[i - 1]);
            if (i + 1 < n)
                r[i] = min(r[i], a[i + 1] - a[i]);
        }
        int lef = 0, rig = r[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            int d = a[i] - a[i - 1];
            if (rig + r[i] > d) {
                ++res;
                int nlef = max(0, d - rig);
                int nrig = min(r[i], d - lef);
                lef = nlef, rig = nrig;
            } else {
                lef = 0;
                rig = r[i];
            }
        }
        cout << res << "\n";
    }
    return 0;
}
