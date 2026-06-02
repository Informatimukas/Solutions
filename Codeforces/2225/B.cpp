#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int res = 0;
        for (int i = 0; i + 1 < s.length(); i++)
            res += s[i] == s[i + 1];
        cout << (res <= 2 ? "YES" : "NO") << "\n";
    }
    return 0;
}
