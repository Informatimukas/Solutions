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
        int st = 0;
        int res = 0;
        for (auto ch : s)
            if (st == 0)
                if (ch == '0')
                    st = 1;
                else {
                    res++;
                    st = 2;
                }
            else if (st == 1) {
                res++;
                st = 2;
            } else if (ch == '0') {
                st = 0;
            } else {
                res++;
                st = 2;
            }
        if (st == 1)
            res++;
        cout << res << "\n";
    }
    return 0;
}
