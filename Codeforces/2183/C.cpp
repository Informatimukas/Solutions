#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        int lef = 2, rig = n;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            int s1 = (mid - 1) / 2;
            int s2 = mid - 1 - s1;
            if (k - s1 <= 0) {
                int tk = s1 - k + 1;
                s1 -= tk;
                s2 += tk;
            } else if (k + s2 > n) {
                int tk = k + s2 - n;
                s2 -= tk;
                s1 += tk;
            }
            if (s1 > s2)
                swap(s1, s2);
            int need = s2 - 1 + mid - 1;
            if (need <= m)
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
