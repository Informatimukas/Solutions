#include <bits/stdc++.h>
using namespace std;

void Subtract(int& st1, int& st2, int& spec1, int& spec2, int& flex, int& res) {
    if (st1 > 0)
        st1--;
    else if (flex > 0)
        flex--;
    else if (spec1 > 0) {
        spec1--;
        flex++;
    } else if (spec2 > 0) {
        spec2--;
        st2++;
    } else if (st2 > 0) {
        res++;
        st2--;
        spec2++;
    } else {
        res++;
        flex++;
    }
}

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
        int st1 = 0, st2 = 0, spec1 = 0, spec2 = 0, flex = 0;
        int res = 0;
        for (auto ch : s) {
            if (ch == '[') st1++;
            else if (ch == ']')
                Subtract(st1, st2, spec1, spec2, flex, res);
            else if (ch == '(') st2++;
            else Subtract(st2, st1, spec2, spec1, flex, res);
        }
        res += (st1 + st2 + flex) / 2;
        cout << res << "\n";
    }
    return 0;
}
