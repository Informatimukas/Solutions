#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        bool hasB = false;
        for (auto& ch : s)
            if (ch == 'B')
                hasB = true;
        while (q--) {
            int a;
            cin >> a;
            if (!hasB) {
                cout << a << "\n";
                continue;
            }
            int pnt = 0, res = 0;
            while (a > 0) {
                if (s[pnt] == 'A')
                    a--;
                else a /= 2;
                pnt = (pnt + 1) % n;
                res++;
            }
            cout << res << "\n";
        }
    }
    return 0;
}
