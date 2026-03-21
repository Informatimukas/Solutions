#include <bits/stdc++.h>
using namespace std;

int Count(const string& s) {
    int res = 1;
    for (int i = 1; i < s.length(); i++)
        res += s[i] != s[i - 1];
    return res;
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
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, Count(s));
            s = s.substr(1, s.length() - 1) + s[0];
        }
        cout << res << "\n";
    }
    return 0;
}
