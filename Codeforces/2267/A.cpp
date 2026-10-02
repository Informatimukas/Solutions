#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        char ch;
        cin >> n >> ch;
        string s;
        cin >> s;
        int l = 0, r = s.length() - 1;
        int res = 0;
        while (l < r) {
            if (s[l] != s[r])
                res += (s[l] != ch) + (s[r] != ch);
            l++; r--;
        }
        cout << res << "\n";
    }
    return 0;
}
