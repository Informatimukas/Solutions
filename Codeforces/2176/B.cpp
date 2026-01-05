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
        string s;
        cin >> s;
        int pnt = 0;
        while (s[pnt] == '0')
            ++pnt;
        int cur = 0, mx = 0;
        for (int i = 1; i <= n; i++) {
            int ind = (pnt + i) % n;
            if (s[ind] == '1') {
                mx = max(mx, cur);
                cur = 0;
            } else ++cur;
        }
        cout << mx << "\n";
    }
    return 0;
}
