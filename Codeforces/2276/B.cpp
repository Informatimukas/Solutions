#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int res = 1, small = 0, big = 0;
        for (int i = 1; i + 1 < s.length(); i++)
            if (s[i - 1] == s[i + 1]) {
                if (s[i] == s[i - 1])
                    big = 1;
                else small = 1;
            }
        res += small + big;
        cout << res << "\n";
    }
    return 0;
}
