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
        if (s[0] == 'u') {
            ++res;
            s[0] = 's';
        }
        if (s[s.length() - 1] == 'u') {
            ++res;
            s[s.length() - 1] = 's';
        }
        for (int i = 0; i + 1 < s.length(); i++)
            if (s[i] == 'u' && s[i + 1] == 'u') {
                ++res;
                s[i + 1] = 's';
            }
        cout << res << "\n";
    }
    return 0;
}
