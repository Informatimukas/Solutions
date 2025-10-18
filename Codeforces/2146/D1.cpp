#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        vector<int> a(r + 1);
        iota(a.begin(), a.end(), 0);
        while (r > 0) {
            int b = 0;
            while (1 << b + 1 <= r)
                b++;
            int oth = ((1 << b + 1) - 1) ^ r;
            int lef = oth, rig = r;
            while (lef < rig) {
                swap(a[lef], a[rig]);
                lef++;
                rig--;
            }
            r = oth - 1;
        }
        long long res = 0;
        for (int i = 0; i < a.size(); i++)
            res += i | a[i];
        cout << res << "\n";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << (i + 1 < a.size() ? ' ' : '\n');
    }
    return 0;
}
