#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int pnt = 0;
        int lef = 0, mid = 0, rig = 0;
        while (pnt < s.length() && s[pnt] == '<') {
            lef++;
            pnt++;
        }
        while (pnt < s.length() && s[pnt] == '*') {
            mid++;
            pnt++;
        }
        while (pnt < s.length() && s[pnt] == '>') {
            rig++;
            pnt++;
        }
        if (pnt < s.length() || mid > 1) {
            cout << "-1\n";
            continue;
        }
        cout << mid + max(lef, rig) << "\n";
    }
    return 0;
}
