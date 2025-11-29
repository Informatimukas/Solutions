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
        int coef1 = 0, coef2 = 0, both = 0, one = 0;
        int cur = 0;
        int pnt = 0;
        int unknown = 0;
        while (pnt < s.length())
            if (s[pnt] == 'X') {
                cur += 10;
                pnt++;
            } else if (s[pnt] == 'V') {
                cur += 5;
                pnt++;
            } else if (s[pnt] == 'I') {
                if (pnt + 1 < s.length() && (s[pnt + 1] == 'X' || s[pnt + 1] == 'V'))
                    cur--;
                else cur++;
                pnt++;
            } else {
                int i = pnt;
                while (pnt < s.length() && s[pnt] == '?')
                    pnt++;
                bool lef = i > 0 && s[i - 1] == 'I';
                bool rig = pnt < s.length() && (s[pnt] == 'X' || s[pnt] == 'V');
                if (lef && rig)
                    if (pnt - i == 1)
                        one++;
                    else {
                        coef1++;
                        coef2++;
                        both += (pnt - i - 2) / 2;
                    }
                else if (lef) {
                    coef2++;
                    both += (pnt - i - 1) / 2;
                } else if (rig) {
                    coef1++;
                    both += (pnt - i - 1) / 2;
                } else both += (pnt - i) / 2;
                unknown += pnt - i;
            }
        while (q--) {
            int X, V, I;
            cin >> X >> V >> I;
            I = min(I, unknown);
            V = min(V, unknown - I);
            X = min(X, unknown - I - V);
            int res = cur + I + 5 * V + 10 * X;
            int has1 = I, has2 = V + X;
            int got = 0;
            int tk = min(min(has1, has2), both);
            got += tk;
            has1 -= tk;
            has2 -= tk;
            tk = min(has1, coef1);
            got += tk;
            has1 -= tk;
            tk = min(has2, coef2);
            got += tk;
            has2 -= tk;
            tk = min(one, has1 + has2);
            got += tk;
            res -= 2 * got;
            cout << res << "\n";
        }
    }
    return 0;
}
