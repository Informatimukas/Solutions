#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        c1 -= a1;
        c2 -= a2;
        c3 -= a3;
        if (c1 > 0) {
            int tk = min(c1, a4);
            c1 -= tk;
            a4 -= tk;
        }
        c3 -= a4;
        if (c2 > 0) {
            int tk = min(c2, a5);
            c2 -= tk;
            a5 -= tk;
        }
        c3 -= a5;
        cout << (c1 >= 0 && c2 >= 0 && c3 >= 0 ? "YES" : "NO") << "\n";
    }
    return 0;
}
