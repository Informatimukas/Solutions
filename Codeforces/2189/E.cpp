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
        if (s == "1") {
            cout << "0\n";
            continue;
        }
        if (s == string(n, '0')) {
            cout << "-1\n";
            continue;
        }
        int cur = 0, mx = 0, best = 0;
        vector<int> L(n);
        for (int i = 0; i < n; i++) {
            cur += s[i] == '1' ? 1 : -1;
            best = max(best, mx - cur - 1);
            L[i] = best;
            mx = max(mx, cur);
        }
        cur = 0, mx = 0, best = 0;
        vector<int> R(n);
        array<int, 3> got{};
        for (int i = n - 1; i >= 0; i--) {
            cur += s[i] == '1' ? 1 : -1;
            best = max(best, mx - cur - 1);
            R[i] = best;
            mx = max(mx, cur);
            if (s[i] == '1') {
                got[1] = max(got[1], max(L[i], R[i]));
                got[2] = max(got[2], L[i] + R[i]);
            }
        }
        if (cur >= 0)
            cout << n << "\n";
        else if (cur + got[1] >= 0 || cur >= -1)
            cout << n + 1 << "\n";
        else if (cur + got[2] >= 0 || cur + got[1] >= -1 || cur >= -2)
            cout << n + 2 << "\n";
        else cout << n + 3 << "\n";
    }
    return 0;
}
