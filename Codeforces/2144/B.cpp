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
        vector<int> p(n);
        vector tk(n + 1, false);
        for (auto& x : p) {
            cin >> x;
            tk[x] = true;
        }
        int pnt = n;
        for (int i = 0; i < n; i++)
            if (p[i] == 0) {
                while (tk[pnt])
                    pnt--;
                p[i] = pnt--;
            }
        int lef = 0;
        while (lef < n && p[lef] == lef + 1)
            lef++;
        if (lef >= n) {
            cout << "0\n";
            continue;
        }
        int rig = n - 1;
        while (p[rig] == rig + 1)
            rig--;
        cout << rig - lef + 1 << "\n";
    }
    return 0;
}
