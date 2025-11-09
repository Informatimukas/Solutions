#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int R0, X, D, n;
        cin >> R0 >> X >> D >> n;
        string s;
        cin >> s;
        int res = 0;
        for (auto& ch : s)
            if (ch == '1' || ch == '2' && R0 < X) {
                res++;
                R0 = max(0, R0 - D);
            }
        cout << res << "\n";
    }
    return 0;
}
