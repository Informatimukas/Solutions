#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int t00 = 0, t11 = 0;
        for (int i = 0; i + 1 < s.length(); i++)
            if (s[i] == '0' && s[i + 1] == '0')
                t00++;
            else if (s[i] == '1' && s[i + 1] == '1')
                t11++;
        int res = 0;
        if (t00 > t11)
            res += (t00 - t11 + 1) / 2;
        cout << res << "\n";
    }
    return 0;
}